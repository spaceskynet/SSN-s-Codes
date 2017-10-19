#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e3+10,INF=1<<31-1;
int a[maxn][maxn],f[maxn][maxn],Next[maxn][maxn];
int main()
{
	int n,m;
	while(scanf("%d%d",&m,&n)==2&&m)
	{
		cls(a,0),cls(f,0),cls(Next,0);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int ans=INF,first=1;
		for(int j=n;j>=1;j--)
		{
			for(int i=1;i<=m;i++)
			{
				if(j==n) f[i][j]=a[i][j];
				else
				{
					int rows[3]={i,i-1,i+1};
					if(i==1) rows[1]=m;
					if(i==m) rows[2]=1;
					sort(rows,rows+3);
					f[i][j]=INF;
					for(int k=0;k<3;k++)
					{
						int v=f[rows[k]][j+1]+a[i][j];
						if(v<f[i][j]) f[i][j]=v,Next[i][j]=rows[k];
					}
				}
				if(j==1&&f[i][j]<ans) ans=f[i][j],first=i;
			}
		}
		printf("%d",first);
		for(int i=Next[first][1],j=2;j<=n;i=Next[i][j],j++) printf(" %d",i);
		printf("\n%d\n",ans);
	}
	return 0;
}
