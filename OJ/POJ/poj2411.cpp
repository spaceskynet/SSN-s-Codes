#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=12,maxs=1<<maxn|1;
ll f[maxn+1][maxs];
int n,m;
void dfs(int,int,int,int);
int main()
{
//	fr();
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		mem(f,0);
		if(n>m) n^=m^=n^=m;
		f[1][0]=1;
		//printf("%d %d\n",n,m);
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				if(f[i][j]) dfs(i,0,j,0);
			}
		}
		printf("%lld\n",f[m+1][0]);
	}
//	fprintf(stderr,"%.3lf s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void dfs(int i,int dep,int s,int nx)
{
	if(dep==n)
	{
		f[i+1][nx]+=f[i][s];
		return;
	}
	if(s&(1<<dep)) dfs(i,dep+1,s,nx);
	if(!(s&(1<<dep))) dfs(i,dep+1,s,nx|(1<<dep));
	if((dep<n-1)&&!(s&(1<<dep))&&!(s&(1<<dep+1))) dfs(i,dep+2,s,nx);
}

