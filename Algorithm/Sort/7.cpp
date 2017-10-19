//归并排序 
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
int tp[maxn],a[maxn];
void mergesort(int x,int y);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(1,n+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
void mergesort(int x,int y)
{
	if(y-x>1)//当序列长度变为1，该子序列有序。 
	{
		int m=x+(y-x)/2;
		int p=x,q=m,i=x;
		mergesort(x,m);
		mergesort(m,y);
		while(p<m||q<y)//任一序列非空，继续合并。 
		{
			if(q>=y||(p<m&&a[p]<=a[q])) tp[i++]=a[p++];//左右序列队首比较，若左小于右，放入铺助数组。 
			else tp[i++]=a[q++];
		}
		for(int i=x;i<y;i++) a[i]=tp[i];
	}
}
