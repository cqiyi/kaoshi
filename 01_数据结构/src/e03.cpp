/*
10����һC�������ܶ���6���ַ�����ÿ�������ȶ�������80�����ܺ��ո��ַ����������ж�ǰ5�����Ƿ�Ϊ��6�������Ӵ������������YES���������NO��

	��ע������Ŀ�ִ���ļ��������� e2.exe����������˺Ż���debugĿ¼�¡���
*/

#include <stdio.h>


int indexof(char *c1, char *c2)
{
	int t, i, j;
	for(i=0; c1[i]!='\0'; i++)
	{
		t = 1; //���赱ǰλ�ü����Ӵ���λ��
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
