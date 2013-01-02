#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define max 100
extern void exit(int);

typedef struct node{
 char d;
 struct node * lchild, * rchild;
}tnode;


void mktree(char pre[],int pres,int pree,char in[],int is,int ie,tnode * * r)
{
 int i;
 if(is>ie||pres>pree)
  * r=NULL;
 else{
  * r=(tnode *) malloc (sizeof(tnode));
  (* r)->d=pre[pres];
  for(i=is;i<=ie;i++)
      if(pre[pres]==in[i])
   {
  mktree(pre,pres+1,pres+i-is,in,is,i-1,&(* r)->lchild); 
   mktree(pre,pres+i-is+1,pree,in,i+1,ie,&(* r)->rchild);
    
    break;
  }
                                                                                                                             if (i>ie){
  printf("error:input contains an error! \n");
  return;
  }
 
 }
}


void postorder(tnode * r)
{
 if (r){
  
  postorder (r->lchild);
  postorder (r->rchild);
  printf("%C",r->d);
 }
}

int leaf(tnode *r)
{
 if (r==NULL)
  return 0;
 else 
  if(r->lchild==NULL && r->rchild==NULL)
   return 1;
  else 
   return (leaf(r->lchild)+leaf(r->rchild));
}

void oneleaf(tnode *r,int *n)
{
 if(r){
  
  if((r->lchild==NULL&&r->rchild!=NULL)||(r->lchild!=NULL&&r->rchild==NULL)){
   printf("%5C",r->d);
   ++(*n);
   }
  oneleaf(r->lchild,n);
  oneleaf(r->rchild,n);
 }
}

void main()
{
 tnode *r;
 int n=0;
 char pre[max],in[max];
 printf("input inorder and postorder!  \n");
 gets(pre);
 gets(in);
 mktree(pre,0,strlen(pre)-1,in,0,strlen(in)-1,&r);
 printf("The preorder is as follows  \n");
 postorder(r);
 printf("\n There are %5d leaves in the tree. \n", leaf(r));
 printf("\nThe one degree node is as follows:\n");
 oneleaf(r,&n);
 printf("\n The one degree nodes number is:%d\n",n);
}