/*���ݽṹ������������Ӧ��

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAXVALUE 200           /*Ȩֵ�����ֵ*/
#define MAXBIT  30             /*���ı���λ��*/
#define MAXNODE 30             /*��ʼ�����Ľ����*/
struct haffnode {
	char data;
	int weight;
	int flag;
	int parent;       /*˫�׽����±�*/
	int leftchild;    /*�����±�*/
	int rightchild;   /*�Һ����±�*/
};
struct haffcode {
	int bit[MAXNODE];
	int start;        /*�������ʼ�±�*/
	char data;
	int weight;       /*�ַ�Ȩֵ*/
};




/*����˵��*/
/************************************************************************/
void pprintf(struct haffcode haffcode[],int n);
/*�������*/
void haffmantree(int weight[],int n,struct haffnode hafftree[],char data[]);
/*������������*/
void haffmancode(struct haffnode hafftree[],int n,struct haffcode haffcode[]);
/*�����������*/
void test(struct haffcode haffcode[],int n);
/*���Ժ���*/
void end();
/*�������溯��*/
/************************************************************************/




void haffmantree(int weight[],int n,struct haffnode hafftree[],char data[])
/*����Ҷ������Ϊn��Ȩֵ����Ϊweight[]�Ĺ�������*/
{
	int i,j,m1,m2,x1,x2;
	/*��������hafftree[]��ʼ����n��Ҷ��㹲��2n-1�����*/
	for(i=0; i<2*n-1; i++) {
		if(i<n) {
			hafftree[i].data=data[i];
			hafftree[i].weight=weight[i];   /*Ҷ���*/
		} else {
			hafftree[i].weight=0;           /*��Ҷ���*/
			hafftree[i].data='\0';
		}
		hafftree[i].parent=0;                     /*��ʼ��û��˫�׽��*/
		hafftree[i].flag=0;
		hafftree[i].leftchild=-1;
		hafftree[i].rightchild=-1;
	}
	for(i=0; i<n-1; i++) {                          /*�����������n-1����Ҷ���*/
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
	/*��n�����Ĺ�������hafftree[]���ɵĹ���������haffcode[]*/
	int i,j,child,parent;
	struct haffcode newcode;
	struct haffcode *cd;
	cd=&newcode;
	for(i=0; i<n; i++) {                                  /*��n�����Ĺ���������*/
		cd->start=MAXBIT-1;                                  /*���ȳ���������һλ��n-1*/
		cd->weight=hafftree[i].weight;
		cd->data=hafftree[i].data;    /*ȡ�ñ����Ӧֵ���ַ�*/
		child=i;
		parent=hafftree[child].parent;
		while(parent!=0) {
			if(hafftree[parent].leftchild==child)
				cd->bit[cd->start]=0;               /*���ӱ���Ϊ0*/
			else
				cd->bit[cd->start]=1;               /*�Һ��ӱ���Ϊ1*/
			cd->start--;
			child=parent;
			parent=hafftree[child].parent;
		}
		for(j=cd->start+1; j<MAXBIT; j++)                   /*����ÿ��Ҷ���ı���͵ȳ��������ʼλ*/
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
		cprintf("�ַ�=%c",myhaffcode[i].data);
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
	cprintf("���������������������ݣ��ڴ˽���Ϊ'this programme is my favorite'");
	printf("\n");
	cprintf("ע��Сд,�ո��ɴ�д��ĸT���棬�����ַ���С��27.\n");
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
			printf("��ϵͳ���Ҳ�����ڸ�%d�ַ���ƥ��ı���\n",i+1);
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
	cprintf("WELCOME!����һ������������������");
	printf("\n");
	cprintf("�������е���ĸ���б�����ڸ����û�����Ҫ�����û���Ҫ����б��롣");
	printf("\n");
	cprintf("ע�⣺������ֻ֧��Сд��ĸ���ո��ô�д��ĸT����!   ");
	printf("\n");
	getch();
	cprintf("Ready?Enter,if you want to begin!\n");
	printf("\n");
	getch();
	cprintf("Now����ʼ��ʾ����������.");
	getch();
	haffmantree(weight,n,myhafftree,data);
	haffmancode(myhafftree,n,myhaffcode);
	pprintf(myhaffcode,n);
	printf("��ִ���Զ�����룬������y������������򽫽���.");
	if((ch=getch())=='y'||ch=='Y')
		test(myhaffcode,n);
	getch();
	exit(1);
}