#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e4+10,maxm=5e4+10,cha=13,INF=~0U>>1;
struct Edge
{
	int from,to,val;
	Edge(){}
	Edge(int from,int to,int val):from(from),to(to),val(val){}
	bool operator < (const Edge &a)const{
		return this->val>a.val;
	}
}E[maxm];
struct edge
{
	int to,next,val;
	edge(){}
	edge(int to,int next,int val):to(to),next(next),val(val){}
}e[maxn<<1];
int Fa[maxn],pre[maxn],tot=0,n,m,fa[maxn][cha+1],dis[maxn][cha+1],dep[maxn];
bool vis[maxn];
int read();
int Find(int);
void add(int,int,int);
void dfs(int);
int lca(int,int);
int query(int,int);
int main()
{
//	fr();
	n=read(),m=read();
	mem(pre,-1),mem(vis,0),mem(dis,0x7f);//dis <- INF
	for(int i=1;i<=n;i++) Fa[i]=i;
	for(int i=1,f,t,v;i<=m;i++)
	{
		f=read(),t=read(),v=read();
		E[i]=Edge(f,t,v);
	}
	sort(E+1,E+m+1);
	int step=0;
	for(int i=1;i<=m&&step<n;i++)
	{
		int fx=Find(E[i].from),fy=Find(E[i].to);
		if(fx^fy)
		{
			Fa[fx]=fy;
			add(E[i].from,E[i].to,E[i].val);
			add(E[i].to,E[i].from,E[i].val);//double edge!
			step++;
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);//every p,may not link
	int q=read();
	while(q--)
	{
		int x=read(),y=read();
		int fx=Find(x),fy=Find(y);
		if(fx^fy) printf("-1\n");
		else printf("%d\n",query(x,y));
	}
//	fprintf(stderr, "%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void dfs(int s)
{
	vis[s]=true;
	for(int i=1;i<=cha;i++)
	{
		if(dep[s]<(1<<i)) break;
		fa[s][i]=fa[fa[s][i-1]][i-1];
		dis[s][i]=min(dis[s][i-1],dis[fa[s][i-1]][i-1]);
	}
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(vis[ito]) continue;
		dep[ito]=dep[s]+1;
		fa[ito][0]=s;
		dis[ito][0]=e[i].val;
		dfs(ito);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) x^=y^=x^=y;
	int d=dep[x]-dep[y];
	for(int i=0;i<=cha;i++)//from 0
	{
		if(d&(1<<i)) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=cha;i>=0;i--)//from 0
	{
		if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int query(int x,int y)
{
	int L=lca(x,y);
	int dx=dep[x]-dep[L],dy=dep[y]-dep[L];
	int ans=INF;
	for(int i=0;i<=cha;i++) 
	{
		if(dx&(1<<i)) ans=min(dis[x][i],ans),x=fa[x][i];
		if(dy&(1<<i)) ans=min(dis[y][i],ans),y=fa[y][i];
	}
	return ans;
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
int Find(int x)
{
	return Fa[x]==x?x:Fa[x]=Find(Fa[x]);
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
