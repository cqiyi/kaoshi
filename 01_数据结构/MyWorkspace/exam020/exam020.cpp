/*数据结构上机题６
１０、 输出两个数组的差集
*/

#include<stdio.h>
void BubbleSort(int a[],int n)
{
	int i,j,k,exchange;
	for(i = 0; i < n-1; i++) {
		exchange = 0;
		for(j = n - 1; j > i; j--) {
			if(a[j] < a[j-1]) {
				k = a[j];
				a[j] = a[j-1];
				a[j-1] = k;
				exchange = 1;
			}
		}
		if(!exchange)
			break;
	}
}
int cha(int a[],int b[],int c[],int countA,int countB)
{
	int i,j,k = 0,flag = 0;
	for(i = 0; i < countA; i++) {
		for(j = 0; j < countB; j++) {
			if(a[i] == b[j])
				flag = 1;
		}
		if(!flag)
			c[k++] = a[i];
		flag = 0;

	}
	return k;
}


void main()
{
	int a[1000],b[1000],c[2000],countA,countB,i,cn;
	printf("Input the a:\n");
	for(i = 0; i <= 1000; i++) {
		scanf("%d",&a[i]);
		if(a[i] == -9999)
			break;
	}
	countA = i;
	BubbleSort(a,countA);
	printf("Input the b:\n");
	for(i = 0; i <= 1000; i++) {
		scanf("%d",&b[i]);
		if(b[i] == -9999)
			break;
	}
	countB = i;
	BubbleSort(b,countB);
	cn = cha(a,b,c,countA,countB);
	for(i = 0; i < cn; i++) {
		if(c[i] == c[i+1])
			c[i+1] = -9999;
	}
	printf("Output the number:\n");
	for(i = 0; i < cn; i++) {
		if(c[i] == -9999)
			continue;
		printf("%d ",c[i]);
		if((i + 1) % 10 == 0)
			printf("\n");
	}
}