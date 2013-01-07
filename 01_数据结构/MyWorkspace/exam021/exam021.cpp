/*数据结构上机题５
查找一个数是否 在一个数组里，若在，输出它在 数组中的位置，否则输出'no'。
*/

#include<stdio.h>
void main()
{
	int a[2000],i,count,temp;
	printf("Input the number:\n");
	scanf("%d",&temp);
	printf("Input a:\n");
	for(i = 0; i < 2000; i++) {
		scanf("%d",&a[i]);
		if(a[i] == -9999)
			break;
	}
	count = i;
	for(i = 0; i < count; i++)
		if(a[i] == temp) {
			printf("Yes,the number is: %d\n",i);
			return;
		}
	printf("No!\n");
}