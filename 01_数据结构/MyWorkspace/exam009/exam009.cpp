/***************************************************************\
8����һC�������ܶ���6���ַ�����ÿ�������ȶ�������80�����ܺ��ո��ַ����������ж�ǰ5�����Ƿ�Ϊ��6�������Ӵ������������YES���������NO��
\***************************************************************/
#include "string.h"
#include "stdio.h"
int substr(char *str1,char *str2)
{
	int n = strlen(str1);
	int m = strlen(str2);
	int j,k;
	for(int i = 0; i<=n-m; i++) {
		j = i;
		k = 0;
		while (str1[j] == str2[k] && k<m) {
			k++;
			j++;
		}
		if(k == m)
			return 1;
	}
	return 0;
}
void main()
{

	char *str[6];
	printf("please enter a num\n");
	int i = 0;
	for(i = 0 ; i<6; i++) {
		printf("%d:",i+1);
		str[i] = new char[80];
		gets(str[i]);
	}
	for(i = 0 ; i < 5; i++) {
		if(substr(str[5],str[i])) {
			printf("%d is Yes",i+1);
		} else {
			printf("%d is NO",i+1);
		}
	}
	for(i = 0 ; i<6; i++) {
		delete[] (str[i]);
	}

}