#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e4,INF=(1<<30);
int n,a[maxn],f[maxn][maxn>>1][2]={0},k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i][0][0]=0,f[i][0][1]=-INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=a[i]+f[i-1][j-1][0];
		}
	}
	printf("%d",max(f[n][k][0],f[n][k][1]));
	return 0;
}

