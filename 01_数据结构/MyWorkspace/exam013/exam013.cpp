/*数据结构：哈夫曼树的应用

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAXVALUE 200           /*权值的最大值*/
#define MAXBIT  30             /*最大的编码位数*/
#define MAXNODE 30             /*初始的最大的结点数*/
struct haffnode {
	char data;
	int weight;
	int flag;
	int parent;       /*双亲结点的下标*/
	int leftchild;    /*左孩子下标*/
	int rightchild;   /*右孩子下标*/
};
struct haffcode {
	int bit[MAXNODE];
	int start;        /*编码的起始下标*/
	char data;
	int weight;       /*字符权值*/
};




/*函数说明*/
/************************************************************************/
void pprintf(struct haffcode haffcode[],int n);
/*输出函数*/
void haffmantree(int weight[],int n,struct haffnode hafftree[],char data[]);
/*建立哈夫曼树*/
void haffmancode(struct haffnode hafftree[],int n,struct haffcode haffcode[]);
/*求哈夫曼编码*/
void test(struct haffcode haffcode[],int n);
/*测试函数*/
void end();
/*结束界面函数*/
/************************************************************************/




void haffmantree(int weight[],int n,struct haffnode hafftree[],char data[])
/*建立叶结点个数为n，权值数组为weight[]的哈夫曼树*/
{
	int i,j,m1,m2,x1,x2;
	/*哈夫曼树hafftree[]初始化，n个叶结点共有2n-1个结点*/
	for(i=0; i<2*n-1; i++) {
		if(i<n) {
			hafftree[i].data=data[i];
			hafftree[i].weight=weight[i];   /*叶结点*/
		} else {
			hafftree[i].weight=0;           /*非叶结点*/
			hafftree[i].data='\0';
		}
		hafftree[i].parent=0;                     /*初始化没有双亲结点*/
		hafftree[i].flag=0;
		hafftree[i].leftchild=-1;
		hafftree[i].rightchild=-1;
	}
	for(i=0; i<n-1; i++) {                          /*构造哈夫曼树n-1个非叶结点*/
		m1=m2=MAXVALUE;
		x1=x2=0;
		for(j=0; j<n+i; j++) {
			if(hafftree[j].weight<m1&&hafftree[j].flag==0) {
				m2=m1;
				x2=x1;
				m1=hafftree[j].weight;
				x1=j;
			} else if(hafftree[j].weight<m2&&hafftree[j].flag==0) {
				m2=hafftree[j].weight;
				x2=j;
			}
		}
		hafftree[x1].parent=n+i;
		hafftree[x2].parent=n+i;
		hafftree[x1].flag=1;
		hafftree[x2].flag=1;
		hafftree[n+i].weight=hafftree[x1].weight+hafftree[x2].weight;
		hafftree[n+i].leftchild=x1;
		hafftree[n+i].rightchild=x2;

	}
}
void haffmancode(struct haffnode hafftree[],int n,struct haffcode haffcode[])
{
	/*由n个结点的哈夫曼树hafftree[]构成的哈夫曼编码haffcode[]*/
	int i,j,child,parent;
	struct haffcode newcode;
	struct haffcode *cd;
	cd=&newcode;
	for(i=0; i<n; i++) {                                  /*求n个结点的哈夫曼编码*/
		cd->start=MAXBIT-1;                                  /*不等长编码的最后一位是n-1*/
		cd->weight=hafftree[i].weight;
		cd->data=hafftree[i].data;    /*取得编码对应值的字符*/
		child=i;
		parent=hafftree[child].parent;
		while(parent!=0) {
			if(hafftree[parent].leftchild==child)
				cd->bit[cd->start]=0;               /*左孩子编码为0*/
			else
				cd->bit[cd->start]=1;               /*右孩子编码为1*/
			cd->start--;
			child=parent;
			parent=hafftree[child].parent;
		}
		for(j=cd->start+1; j<MAXBIT; j++)                   /*保存每个叶结点的编码和等长编码的起始位*/
			haffcode[i].bit[j]=cd->bit[j];
		haffcode[i].data=cd->data;
		haffcode[i].start=cd->start;
		haffcode[i].weight=cd->weight;
	}
}
void pprintf(struct haffcode myhaffcode[],int n)
{
	int i,j,count=0;
	for(i=0; i<n; i++) {
		cprintf("字符=%c",myhaffcode[i].data);
		printf("              ");
		cprintf("weight=%3d",myhaffcode[i].weight);
		printf("              ");
		cprintf("haffcode=");
		for(j=myhaffcode[i].start+1; j<MAXBIT; j++)
			cprintf("%d",myhaffcode[i].bit[j]);
		printf("\n");
		count++;
		if(count==21)
			getch();

	}
}
void test(struct haffcode haffcode[],int n)
{
	int i,j,k,s;
	char sstring[MAXNODE];
	struct haffcode newhaffcode[MAXNODE];
	j=0;
	cprintf("请输入哈夫曼编码测试数据，在此建议为'this programme is my favorite'");
	printf("\n");
	cprintf("注意小写,空格由大写字母T代替，并且字符数小于27.\n");
	scanf("%s",sstring);
	if(strlen(sstring)>=MAXNODE) {
		printf("you input the data number >=MAXNODE.");
		exit(1);
	}
	for(i=0; i<strlen(sstring); i++) {
		for(j=0; j<MAXBIT; j++)
			if(sstring[i]==haffcode[j].data) {
				k=j;
				break;
			}
		if(k<0||k>MAXNODE-1) {
			printf("在系统中找不到与第个%d字符相匹配的编码\n",i+1);
			continue;
		}
		newhaffcode[i].start=haffcode[k].start;
		newhaffcode[i].weight=haffcode[k].weight;
		newhaffcode[i].data=haffcode[k].data;
		for(s=haffcode[k].start+1; s<MAXBIT; s++)
			newhaffcode[i].bit[s]=haffcode[k].bit[s];
	}

	pprintf(newhaffcode,strlen(sstring));
}
void main()
{
	int i,j,n=27;
	char ch;
	int weight[27]= {186,64,13,22,32,103,21,15,47,
	                 57,1,5,32,20,57,63,15,1,48,
	                 51,80,23,8,18,1,16,1
	                };
	char data[28]= {'T','a','b','c','d','e','f','g','h',
	                'i','j','k','l','m','n','o','p','q',
	                'r','s','t','u','v','w','x','y','z'
	               };
	struct haffnode newhaffnode[2*MAXNODE-1];
	struct haffcode newcode[MAXNODE];
	struct haffnode *myhafftree=newhaffnode;
	struct haffcode *myhaffcode=newcode;
	if(n>MAXNODE) {
		printf("you input the haffnode > MAXNODE,so you input the data is wrong");
		printf("\n");
		exit(1);
	}
	cprintf("WELCOME!这是一个求哈夫曼编码的问题");
	printf("\n");
	cprintf("即对所有的字母进行编码后，在根据用户的需要，对用户的要求进行编码。");
	printf("\n");
	cprintf("注意：本程序只支持小写字母，空格用大写字母T代替!   ");
	printf("\n");
	getch();
	cprintf("Ready?Enter,if you want to begin!\n");
	printf("\n");
	getch();
	cprintf("Now，开始演示哈夫曼编码.");
	getch();
	haffmantree(weight,n,myhafftree,data);
	haffmancode(myhafftree,n,myhaffcode);
	pprintf(myhaffcode,n);
	printf("若执行自定义编译，请输入y继续。否则程序将结束.");
	if((ch=getch())=='y'||ch=='Y')
		test(myhaffcode,n);
	getch();
	exit(1);
}