/*1. ��һC�������ܶ��뼯��A��һ����������-9999Ϊ������ǣ���������С��1000���ͼ���B ��һ����������-9999Ϊ������ǣ���������С��1000�������㲢�Դ�С����Ĵ������A-B ������Ԫ��(ΪA��B����ʱ��ͬһ�������ܳ��ֶ�Σ���A��B�Ĳ��ͬһ�������ܳ��ֶ��)�� ��ע������Ŀ�ִ���ļ��������� e1.exe��

��ע������Ŀ�ִ���ļ��������� e4.exe��
*/
#include <stdio.h>

void BubbleSort(int r[],int n) {
	//ð������(��С����)
	int i,j,k;
	int exchange;
	for(i=0; i<=n; i++) {
		exchange=0;
		for(j=n-1; j>=i; j--)
			if(r[j+1]<r[j]) {
				k=r[j+1];
				r[j+1]=r[j];
				r[j]=k;
				exchange=1;
			}
		if(!exchange)
			break;
	}
}


int DisaSameYs(int r[],int n) {
	//��������r[]�е��ظ�Ԫ��,����������������ʣ���Ԫ�ظ���
	int w,x,y;
	for(w=0; w<=n; w++) {
		for(x=w+1; x<=n; x++) {
			if(r[w]==r[x]) {
				n--;
				for(y=x; y<=n; y++) {
					r[y]=r[y+1];
				}//endfor
				x--;
			}//endif
		}//endfor
	}//endfor

	return n;
}


int cha(int m[],int n[],int l[],int Countaa,int Countbb) {
	//��
	int i=0,j=0,k=0;
	int exch;
	while(i<=Countaa) {
		exch=0;//��������Ϊ0
		for(j=0; j<=Countbb; j++) {
			//�ü��ϵĵ�һ��Ԫ�طֱ����һ�����ϵĸ�Ԫ����Ƚ�
			//Ȼ�����õڶ���Ԫ��(ֱ�����һ��Ԫ��)����һ�����ϵĸ�Ԫ����Ƚ�
			if(m[i]==n[j]) {
				//�����ͬ������������Ϊ1
				exch=1;
				break;
			}//endif
		}//endfor
		if(!exch) {
			//���û����ͬ�ľͱ���m[i]��l[]��
			l[k]=m[i];
			k++;
		}
		i++;
	}//endwhile

	return k;
}

/*
void testds(int r[],int n)
{//�������������е��ظ�Ԫ�ص�Ч��������ѭ�����
 int z;
 for(z=0;z<=n;z++)
 {
  printf("%d",r[z]);
 }
 printf("\n");
}
*/

void main() {
	int a[1000], b[1000],c[2000];
	int exchange=0;
	int i,j,k,CountA,CountB,CountC;

	printf("input a\n");
	for(i=0; i<=1000; i++) {
		scanf("%d",&a[i]);
		if(a[i]==-9999)
			break;
	}
	CountA=i-1;
	BubbleSort(a,CountA);

	CountA=DisaSameYs(a,CountA);
// testds(a,CountA);

	printf("\ninput b\n");
	for(i=0; i<=1000; i++) {
		scanf("%d",&b[i]);
		if(b[i]==-9999)
			break;
	}
	CountB=i-1;
	BubbleSort(b,CountB);

	CountB=DisaSameYs(b,CountB);
//testds(b,CountB);

	CountC=cha(a,b,c,CountA,CountB);

	printf("\n\n");
	for(i=0; i<=CountC-1; i++) {
		printf("%d ",c[i]);
	}
	printf("\n");
}