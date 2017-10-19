//spaceskynet 2017-07-14 dp 
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
int n,m,f[maxn]={0},is[maxn][2]={0},a[maxn]={0};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		is[a[i]][0]=1;
		is[a[i]][1]=i;
	}
	f[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		f[i]=f[i+1]+((is[a[i]][0]&&i>=is[a[i]][1])?1:0);
	}
	while(m--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
	return 0;
}
