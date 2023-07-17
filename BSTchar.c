// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
  char key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(char item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// preorderTraversal traversal
void preorderTraversal(struct node* root,FILE *fp) {
  if (root == NULL)
  {return;
  }
  printf("%c ", root->key);
  fprintf(fp,"%c ",root->key);
  preorderTraversal(root->left,fp);
  preorderTraversal(root->right,fp);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root,FILE *fp) {
  if (root == NULL)
  {return;
  }
  postorderTraversal(root->left,fp);
  postorderTraversal(root->right,fp);
  printf("%c ", root->key);
  fprintf(fp,"%c ",root->key);
}

// Inorder Traversal
void inorder(struct node *root,FILE *fpi) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left,fpi);

    // Traverse root
    printf("%c ", root->key);
    fprintf(fpi,"%c ",root->key);

    // Traverse right
    inorder(root->right,fpi);
  }
}

// Insert a node
struct node *insert(struct node *node, char key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void rad(FILE *fp,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%c",rand()%(91-65)+65);
    }
}

// Driver code
int main() {
    clock_t start, end;
     double t;

    FILE *fpi,*fppo,*fppre,*fpr;
    fpr=fopen("F:\Random.txt","w");
    fpi=fopen("F:\Inorder.txt","w");
    fppo=fopen("F:\Postorder.txt","w");
    fppre=fopen("F:\Preorder.txt","w");
    rad(fpr,26);
    fclose(fpr);
    fclose(fppre);
    fclose(fpi);
    fclose(fppo);
    int n;
    char x;
    fpr=fopen("F:\Random.txt","r");
     fpi=fopen("F:\Inorder.txt","a");
    fppo=fopen("F:\Postorder.txt","a");
    fppre=fopen("F:\Preorder.txt","a");
    fprintf(fpi,"Inorder Traversel:\n");
    fprintf(fppo,"Postorder Traversel:\n");
    fprintf(fppre,"Preorder Traversel:\n");

  struct node *root1 = NULL;
    struct node *root2 = NULL;
      struct node *root3 = NULL;


  for(int i=0;i<26;i++)
  {

    fscanf(fpr,"%c",&x);
      root1=insert(root1,x);

  }
  /*root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);*/

  printf("Inorder traversal: ");
  start = clock();
  inorder(root1,fpi);
  start = clock()-start;
  t=((double)start) / CLOCKS_PER_SEC;
  printf("\nTime taken by inorder traversing:%f secs",t);
    printf("\n");
 printf("\n");


  printf("Postorder traversal: ");
  start = clock();
  postorderTraversal(root1,fppo);
   start = clock()-start;
    t=((double)start) / CLOCKS_PER_SEC;
  printf("\n Time taken by Postorder traversing:%f secs",t);
 printf("\n");
  printf("\n");


  printf("Preorder traversal: ");
  start = clock();
  preorderTraversal(root1,fppre);
   start = clock() - start;
  t=((double)start) / CLOCKS_PER_SEC;
  printf("\nTime taken by Preorder traversing:%f secs",t);
 printf("\n");


  /*printf("\nAfter deleting 6\n");
  root = deleteNode(root, 6);
  printf("Inorder traversal: ");
  inorder(root);*/
}
