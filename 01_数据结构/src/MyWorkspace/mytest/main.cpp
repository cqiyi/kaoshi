#include <stdlib.h>
#include <stdio.h>

int main(){
	int i, j;
	int *i0, *j0;
	i0 = &i;
	j0 = &j;

	i0 = NULL;
	*j0 = NULL;
	system("pause");
}