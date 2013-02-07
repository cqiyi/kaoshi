//////////////////////////////////////////////////////
//Ä£Ê½Æ¥Åä

#include <stdio.h>
#include <string.h>

void main()
{
	char ch[2000];
	printf("Input STRING:\n");
	gets(ch);
	printf("\n%s,%d\n", ch, strlen(ch));
	printf("\n%d\n", strcmp(ch, "abc"));
}