/*���ݽṹ�ϻ��⣵
����һ�����Ƿ� ��һ����������ڣ�������� �����е�λ�ã��������'no'��
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