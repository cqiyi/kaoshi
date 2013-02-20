/*
10．编一C程序，它能读入6个字符串（每个串长度都不大于80，可能含空格字符），依次判断前5个串是否为第6个串的子串，若是则输出YES；否则输出NO。

	（注：程序的可执行文件名必须是 e2.exe，存于你的账号或其debug目录下。）
*/

#include <stdio.h>


int indexof(char *c1, char *c2)
{
	int t, i, j;
	for(i=0; c1[i]!='\0'; i++)
	{
		t = 1; //假设当前位置即是子串的位置
		for(j=0; c2[j]!='\0'; j++)
		{
			char c0 = c1[i+j];
			if(c0=='\0' || c0 != c2[j])
			{
				t = 0;
				break;
			}//end if
		}//end for
		if(t) return i;
	}
	return -1;
}

void main()
{
	char ch[6][80];
	int i, j, r;
	for(i=0; i<6; i++)
	{
		printf("%d, input string:\n", i+1);
		gets(ch[i]);
	}

	for(i=0; i<5; i++)
	{
		printf("\n%s\n", indexof(ch[5], ch[i])>=0?"YES":"NO");
	}
}
