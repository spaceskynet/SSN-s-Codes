#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5,INF=(1<<30)-1;
int f[maxn]={0},g[maxn]={0},a[maxn]={0},ans=0,n=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=g[i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i]&&f[j]+1>f[i])
			{
				f[i]=f[j]+1;
			}
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]<a[i]&&g[j]+1>g[i])
			{
				g[i]=g[j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++) ans=max(f[i]+g[i]-1,ans);
	printf("%d",n-ans);
	return 0;
}

