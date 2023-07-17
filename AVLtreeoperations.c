// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>
int COUNT=5;
// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
    int x=0;
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
        x=1;
      } else
        *root = *temp;
      free(temp);
      x=1;
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
      x=1;
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  if(x==0){
    printf("%d is not found \n",key);
}
  return root;
}

// Print the tree
void printPreOrder(struct Node *root,FILE *fp) {
  if (root != NULL) {
    printf("%d ->", root->key);
    fprintf(fp,"%d ->",root->key);
    printPreOrder(root->left,fp);
    printPreOrder(root->right,fp);
  }
}
void rad(FILE *fp,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d\t",rand()%100);
    }
}
void postorderTraversal(struct Node* root,FILE *fp) {
  if (root == NULL)
  {return;
  }
  postorderTraversal(root->left,fp);
  postorderTraversal(root->right,fp);
  printf("%d ->", root->key);
  fprintf(fp,"%d ->",root->key);
}

void inorder(struct Node *root,FILE *fpi) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left,fpi);

    // Traverse root
    printf("%d -> ", root->key);
    fprintf(fpi,"%d ->",root->key);

    // Traverse right
    inorder(root->right,fpi);
  }
}

void print2DUtil(struct Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


int main() {

  struct Node *root = NULL;
  FILE *fpr,*fppre,*fpi,*fppo;
  fpi=fopen("F:\Inorder.txt","w");
    fppo=fopen("F:\Postorder.txt","w");
  fpr=fopen("F:\Random.txt","w");
  fppre=fopen("F:\PreOrder.txt","w");
  rad(fpr,50);
  fclose(fpr);
  fclose(fppre);
   fclose(fpi);
    fclose(fppo);
 /* root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 6);
  root = insertNode(root, 3);
  root = insertNode(root, 8);
  root = insertNode(root, 9);
  printPreOrder(root);*/
  fpr=fopen("F:\Random.txt","r");
  fpi=fopen("F:\Inorder.txt","a");
    fppo=fopen("F:\Postorder.txt","a");
  fppre=fopen("F:\PreOrder.txt","a");
  int n,x;
  printf("Enter the no of data you want to insert:\n");
  scanf("%d",&n);
  /*printf("Enter the data:\n");*/
  for(int i=0;i<n;i++)
  {
      fscanf(fpr,"%d",&x);
      root=insertNode(root,x);
  }
  printf("\n");
  printf("PreOrder  traversal:\n");
  printPreOrder(root,fppre);
printf("\n");
   printf("Postorder traversal: ");
    postorderTraversal(root,fppo);
printf("\n");
     printf("Inorder traversal: ");
    inorder(root,fpi);

  printf("\n");
  print2D(root);
  printf("\n");
  printf("\nEnter the data you want to delete:\n");
  scanf("%d",&x);
  printf("\n");
  root = deleteNode(root,x);

printf("\n");
  printf("\nAfter deletion: ");
  printf("PreOrder  traversal:\n");
  printPreOrder(root,fppre);
printf("\n");
   printf("Postorder traversal: ");
    postorderTraversal(root,fppo);
printf("\n");
     printf("Inorder traversal: ");
    inorder(root,fpi);
   printf("\n");
  print2D(root);
  printf("\n");

  return 0;
}
