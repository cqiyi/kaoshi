/*1. 编一C程序，它能读入集合A的一串整数（以-9999为结束标记，整数个数小于1000）和集合B 的一串整数（以-9999为结束标记，整数个数小于1000），计算并以从小到大的次序输出A-B 的所有元素(为A或B输入时，同一个数可能出现多次，而A与B的差集中同一个数不能出现多次)。 （注：程序的可执行文件名必须是 e1.exe）

（注：程序的可执行文件名必须是 e4.exe）
*/
#include <stdio.h>

void BubbleSort(int r[],int n) {
	//冒泡排序(有小到大)
	int i,j,k;
	int exchange;
	for(i=0; i<=n; i++) {
		exchange=0;
		for(j=n-1; j>=i; j--)
			if(r[j+1]<r[j]) {
				k=r[j+1];
				r[j+1]=r[j];
				r[j]=k;
				exchange=1;
			}
		if(!exchange)
			break;
	}
}


int DisaSameYs(int r[],int n) {
	//消除数组r[]中的重复元素,并返回消除后数组剩余的元素个数
	int w,x,y;
	for(w=0; w<=n; w++) {
		for(x=w+1; x<=n; x++) {
			if(r[w]==r[x]) {
				n--;
				for(y=x; y<=n; y++) {
					r[y]=r[y+1];
				}//endfor
				x--;
			}//endif
		}//endfor
	}//endfor

	return n;
}


int cha(int m[],int n[],int l[],int Countaa,int Countbb) {
	//求差集
	int i=0,j=0,k=0;
	int exch;
	while(i<=Countaa) {
		exch=0;//交换变量为0
		for(j=0; j<=Countbb; j++) {
			//用集合的第一个元素分别和另一个集合的各元素相比较
			//然后再用第二个元素(直到最后一个元素)和另一个集合的各元素相比较
			if(m[i]==n[j]) {
				//如果相同，交换变量变为1
				exch=1;
				break;
			}//endif
		}//endfor
		if(!exch) {
			//如果没有相同的就保存m[i]到l[]中
			l[k]=m[i];
			k++;
		}
		i++;
	}//endwhile

	return k;
}

/*
void testds(int r[],int n)
{//测试消除数组中的重复元素的效果用下列循环输出
 int z;
 for(z=0;z<=n;z++)
 {
  printf("%d",r[z]);
 }
 printf("\n");
}
*/

void main() {
	int a[1000], b[1000],c[2000];
	int exchange=0;
	int i,j,k,CountA,CountB,CountC;

	printf("input a\n");
	for(i=0; i<=1000; i++) {
		scanf("%d",&a[i]);
		if(a[i]==-9999)
			break;
	}
	CountA=i-1;
	BubbleSort(a,CountA);

	CountA=DisaSameYs(a,CountA);
// testds(a,CountA);

	printf("\ninput b\n");
	for(i=0; i<=1000; i++) {
		scanf("%d",&b[i]);
		if(b[i]==-9999)
			break;
	}
	CountB=i-1;
	BubbleSort(b,CountB);

	CountB=DisaSameYs(b,CountB);
//testds(b,CountB);

	CountC=cha(a,b,c,CountA,CountB);

	printf("\n\n");
	for(i=0; i<=CountC-1; i++) {
		printf("%d ",c[i]);
	}
	printf("\n");
}