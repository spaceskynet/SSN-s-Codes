#include<cstdio>
#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=2e3+10,INF=~0U>>1;
int n[maxn*5],m[maxn*5],C[maxn][maxn],ans[maxn][maxn],man=-INF,mam=-INF,t,k;
int main()
{
	scanf("%d%d",&t,&k);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n[i],&m[i]);
		man=max(man,n[i]);
		mam=max(mam,m[i]);
	}
	int tmp=0;
	for(int i=0;i<=man;i++,tmp=0)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
			tmp+=(C[i][j]==0);
			if(i) ans[i][j]=ans[i-1][j]+tmp;
			else ans[i][j]=tmp;
		}
		for(int j=i+1;j<=mam;j++)
		{
			if(i) ans[i][j]=ans[i-1][j]+tmp;
			else ans[i][j]=tmp;
		}
	}
	for(int i=1;i<=t;i++) printf("%d\n",ans[n[i]][m[i]]);
	return 0;
}
