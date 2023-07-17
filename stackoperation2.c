#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

struct stack{

int item[SIZE];
int top;
};

int count=0;

typedef struct stack stk1;

int isfull(stk1 *s)
{
    if(s->top==(SIZE-1))
        return 1;
    else
        return 0;
}

int isEmpty(stk1 *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int push(stk1 *s,int data)
{
    s->top++;
    count++;
    return s->item[s->top]=data;
}

int pop(stk1 *s)
{
    int data;
    data=s->item[s->top];
    s->top--;
    count--;
    return data;
}

void display(stk1 *s)
{
    printf("Stack contains:\n");
    for(int i=s->top;i>=0;i--)
    {
        printf("%d \n",s->item[i]);
    }
}

void rad(FILE *f,int n,int h, int l)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        fprintf(f,"%d\t",rand()%(h-l)+l);
    }
}

int peek(stk1 *s)
{
    return s->item[s->top];
}


int main()
{
    stk1 stk;
    stk.top=-1;
    int x,y,z,n=0,k=0;
    int ch;
    int j=1;
    FILE *fp,*fp1,*fp2,*fp3,*fp4;
    fp=fopen("F:\data.txt","w");
    fp1=fopen("F:\pushdata.txt","w");
    fp2=fopen("F:\stacklog.txt","w");
    fp3=fopen("F:\popdata.txt","w");
    rad(fp,50,1,20);
    rad(fp4,50,1,10);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fp=fopen("F:\data.txt","r");
    fp1=fopen("F:\pushdata.txt","a");
    fp2=fopen("F:\stacklog.txt","a");
    fp3=fopen("F:\popdata.txt","a");
    fprintf(fp3,"Popped Data: \n");
    fprintf(fp1,"Pushed Data: \n");
    fprintf(fp2,"Stack Operations: \n");
    while(1)
    {
    printf("1.Push 2.Pop 3.Display 4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                if(isfull(&stk))
                {
                    printf("stack full.\n");
                    break;
                }
                printf("Enter no of times you want to push:\n");
                scanf("%d",&n);
                if(n>50){
                    printf("stack memory exceeds.\n");
                    break;
                }
                for(int i=0;i<n;i++){
                fscanf(fp,"%d",&x);
                z=push(&stk,x);
                fprintf(fp1,"%d ",z);
                fprintf(fp2,"%d.Push \n",j++);
                }
                printf("Data Pushed %d times.\n",n);
                break;
        case 2: if(isEmpty(&stk))
                {
                    printf("Stack Empty.\n");
                    break;
                }
                printf("Enter no of elements you want to pop:\n elements remaining in stack : %d.\n",count);
                scanf("%d",&n);
                if(n>count){
                    printf("Stack underflow.\n");
                    break;
                }for(int i=0;i<n;i++)
                {
                y=pop(&stk);
                fprintf(fp2,"%d.Pop \n",j++);
                fprintf(fp3,"%d ",y);
                }
                fclose(fp1);
                fp1=fopen("F:\pushdata.txt","w");
                fprintf(fp1,"Pushed Data: \n");
                for(int i=0;i<count;i++)
                {
                    fprintf(fp1,"%d ",stk.item[i]);
                }
                //printf("Data popped : %d \n",y);
                printf("Data popped %d times.\n",n);
                break;
        case 3: display(&stk);
                break;

        default:fclose(fp);
                fclose(fp4);
                exit(0);
    }
    }


}
