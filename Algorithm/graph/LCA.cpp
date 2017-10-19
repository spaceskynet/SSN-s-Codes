#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=5e5+10,cha=20;
struct edge
{
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxn<<1];
int fa[maxn][cha],pre[maxn],dep[maxn],tot=0,n,m,s,mxlog=0;
bool vis[maxn];
int read();
void dfs(int);
void add(int,int);
int lca(int,int);
int main()
{
//	fr();
	mem(pre,-1);
	n=read(),m=read(),s=read();
	mxlog=log(n)/log(2);
	for(int i=2,f,t;i<=n;i++)
	{
		f=read(),t=read();
		add(f,t),add(t,f);
	}
	dep[s]=1;dfs(s);
	while(m--)
	{
		int x=read(),y=read();
		printf("%d\n",lca(x,y));
	}
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to)
{
	e[++tot]=edge(to,pre[from]);pre[from]=tot;
}
void dfs(int s)
{
	vis[s]=true;
	for(int i=1;i<=mxlog;i++)
	{
		if(dep[s]<(1<<i)) break;
		fa[s][i]=fa[fa[s][i-1]][i-1];
	}
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(vis[ito]) continue;
		dep[ito]=dep[s]+1;
		fa[ito][0]=s;
		dfs(ito);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) x^=y^=x^=y;
	int d=dep[x]-dep[y];
	for(int i=0;i<=mxlog;i++)
	{
		if(!(d&(1<<i))) continue;
		x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=mxlog;i>=0;i--)
	{
		if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
