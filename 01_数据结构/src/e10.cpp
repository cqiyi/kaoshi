#include <stdio.h>
#include <string.h>

void main()
{
	int i,j, k1,k2,c[66],s,k,count=0,flag=0;
	int a[66];
	int b[66];
	printf("请输入66个数到a中：\n");
	for(i=0; i<66; i++)
		scanf("%d",&a[i]);
	printf("请输入66个数到b中：\n");
	for(i=0; i<66; i++)
		scanf("%d",&b[i]);
	for(i=0; i<11; i++) {
		for(k=0; k<11; k++) {
			s=0;
			for(j=0; j<11&&i>=j; j++)
				k1=i*(i+1)/2+j;
			if(j>=k) 
				k2=j*(j+1)/2+i;
			else 
				continue;
			s+=a[k1]*b[k2];
			flag=1;
		}
		if(flag) {
			c[count++]=s;
			flag=0;
		}
	}
	for(i=0; i<66; i++) {
		printf("%d",c[i]);
	}
}
