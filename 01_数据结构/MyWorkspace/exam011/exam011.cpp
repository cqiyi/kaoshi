#include <stdio.h>
#include <string.h>
#define max 100

int find(int a[],int n)
{
	int i,j=0;
	for(i=1; i<n; i++)
		if(a[i]==a[n])
			j++;
	return (j);
}

void read(int a[])
{
	int x,i=1;
	printf("Input the date :\n");
	do
	{
		scanf("%d",&x);
		if(x==-9999)return;
		a[i++]=x;
	}
	while(9);

}
void main()
{
	int a[max],n;
	read(a);
	printf("Input n:\n");
	scanf("%d",&n);
	printf("\nThere are %d dimension.\n",find(a,n));
}