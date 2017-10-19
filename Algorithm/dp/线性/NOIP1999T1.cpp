#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e5,INF=(1<<30)-1;
int f[maxn]={0},g[maxn]={0},a[maxn]={0},n=0,ans[2]={-INF,-INF};
int main()
{
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) ;
	while(scanf("%d",&a[++n])!=EOF) f[n]=g[n]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>=a[i]&&f[j]+1>f[i])
			{
				f[i]=f[j]+1;
			}
			if(a[j]<a[i]&&g[j]+1>g[i])
			{
				g[i]=g[j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++) ans[0]=max(ans[0],f[i]),ans[1]=max(ans[1],g[i]);//�ύʱ"i<n" 
	printf("%d\n%d",ans[0],ans[1]);
	return 0;
}
