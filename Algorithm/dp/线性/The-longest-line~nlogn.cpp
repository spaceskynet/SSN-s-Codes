#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10,INF=(1<<31)-1;
int n,a,stack[maxn],top=0;
void binary_search(int,int,int*);
int main()
{
	scanf("%d",&n);
	stack[0]=-INF;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a);
		if(a>stack[top])
		{
			stack[++top]=a;
		}
		else binary_search(a,top,stack);
	}
	printf("%d",top);
	return 0;
}
void binary_search(int x,int r,int* s)
{
	int l=1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x>s[mid]) l=mid+1;
		else r=mid-1;
	}
	s[l]=x;
}
