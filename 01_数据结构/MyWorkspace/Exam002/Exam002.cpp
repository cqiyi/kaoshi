/****************************************
1. Ä£Ê½Æ¥Åä  
****************************************/

#include <stdio.h> 
#include <string.h> 

typedef struct{ 
//int ch[2000]; 
	char ch[2000]; 
	int length; 
}SeqString; 

int NaiveStrMatch(SeqString T,SeqString P) 
{ 
	int i,j,k; 
	int m=P.length; 
	int n=T.length; 
	for(i=0;i<=n-m;i++) 
	{ 
		j=0;k=i; 
		while(j<m&&T.ch[k]==P.ch[j]) 
		{ 
			k++;j++; 
		} 
		if(j==m) return i; 
		
	}//endfor 
	return -1; 
}//NaiveStrMatch 

SeqString CreatStr(SeqString R) 
{ 
	int i; 
	printf("input data\n"); 
	for(i=0;i<2000;i++) 
	{ 
		//scanf("%d",&R.ch[i]);
		//if(R.ch[i]==-9999)
		scanf("%s",&R.ch[i]); 
		if(!(strcmp(&R.ch[i],"-9999"))) 
		break; 
	} 
	R.length=i-1; 
	return R; 
} 

void main() 
{ 
	int n; 
	SeqString Str1; 
	Str1=CreatStr(Str1); 
	SeqString Str2; 
	Str2=CreatStr(Str2); 
	n=NaiveStrMatch(Str1,Str2); 
	printf("%d\n",n); 
} 
