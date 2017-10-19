#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=105,INF=(1<<30),maxx=maxn*maxn*2;
int a[maxn]={0},b[maxn]={0},f[maxx+10],n,k,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]=a[i]-b[i]*k;
	memset(f,128,sizeof(f));
	f[maxx>>1]=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=0)
		{
			for(int j=maxx;j>=b[i];j--)
			{
				f[j]=max(f[j],f[j-b[i]]+a[i]);
			}
		}
		else
		{
			for(int j=0;j<=maxx+b[i];j++)
			{
				f[j]=max(f[j],f[j-b[i]]+a[i]);
			}
		}
	}
	ans=(f[maxx>>1]>=0?f[maxx>>1]:-1);
	printf("%d",ans);
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=105,INF=(1<<30),maxx=3e4+1000;
int a[maxn]={0},b[maxn]={0},f[maxx][2],n,k,flag=0,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]=a[i]-b[i]*k;
	for(int i=1;i<=maxx;i++) f[i][0]=-INF;
	f[maxx>>1][0]=0;
	for(int i=1;i<=n;i++,flag^=1)
	{
		for(int j=0;j<=maxx;j++)
		{
			f[j][flag]=f[j][flag^1];
			if(0<=j-b[i]&&j-b[i]<=maxx) f[j][flag]=max(f[j][flag],f[j-b[i]][flag^1]+a[i]);
		}
	}
	ans=(f[maxx>>1][flag]>=0?f[maxx>>1][flag]:-1);
	printf("%d",ans);
	return 0;
}
*/
