/*=-------------------------------------------
 ���ݽṹ�ϻ��⣴
��һC�������ܶ���һ��������������2000������-9999Ϊ������ǣ�����һ����n���ж�n�Ƿ�����һ�����У����ǣ������yes���������Ǵ������е���ţ���Ŵ�0��ʼ�����������no��(��������ʱ�����ڵ������ÿո����)��
��ע������Ŀ�ִ���ļ��������� e6.exe��
*/

#include <stdio.h>

typedef struct {
	int data[2000];
	int length;
} SeqList;

void main()
{
	int i,k=0,num;
	SeqList a;
	printf("input data\n");
	for(i=0; i<2000; i++) {
		scanf("%d",&a.data[i]);
		if(a.data[i]==-9999)
			break;
	}
	a.length=i-1;

	printf("input the number\n");
	scanf("%d",&num);
	for(i=0; i<=a.length; i++) {
		k++;
		if(a.data[i]==num) {
			printf("yes\n");
			printf(" is at %d",k);
			printf("\n");

		}
	}
	printf("\nno\n");
}