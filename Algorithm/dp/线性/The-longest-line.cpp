#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e5,INF=(1<<30)-1;
int f[maxn]={0},a[maxn]={0},n,ans=-INF;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i]&&f[j]+1>f[i])
				f[i]=f[j]+1;
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}


