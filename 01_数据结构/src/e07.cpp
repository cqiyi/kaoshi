/*�ڶ��⣺��ð�ݽ����Ż���ʹ���þ������ٵ���������ӡ�����Ľ������ӡ�Ƚ�������
*/
//��ĭ����

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
void InputData( int *a,int *len );
void BubbleSort( int *a,int len );

void main( ) {
	int a[MAX],len=0;
	InputData(a,&len);
	BubbleSort( a,len );
	system("pause");
}
void InputData( int *a,int *len ) {
	int d;
	printf("����������(����-1��ʾ����\n");
	do {
		scanf("%d",&d);
		if( d==-1 )
			break;
		a[(*len)++]=d;
	} while(1);
}
void BubbleSort( int *a,int len ) {
	int lastexchange,i,j,temp,step;
	i=0;
	step=0;
	while(i<len-1) {
		step++;
		lastexchange=len-1;
		for( j=len-1; j>i; j-- ) {
			if( a[j]<a[j-1] ) {
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				lastexchange=j;
			}
		}
		i=lastexchange;
	}
	printf("����������:%d\n",step);
	printf("��ĭ����Ľ����:\n");
	j=0;
	for(i=0; i<len; i++) {
		printf("%4d",a[i]);
		if((++j)%5==0 )
			printf("\n");
	}
	printf("\n");
}


//��ð�ݵ��Ż�
int counter=0;//����
void bubblesort(int a[],int n) {
	int lastexchange,j,i=n-1;

	while(i>0) {
		lastexchange=0;
		counter++;
		for(j=0; j<i; j++) {
			if(a[j+1]<a[j]) {
				//����a[j]��a[j+1];
				lastexchange=j;
			}
		}

		i=lastexchange;
	}
}