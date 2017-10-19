#include<iostream>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=1e5,INF=(1<<30)-1;
struct edge
{
	int to,next;	
}e[maxn];
struct zkw
{
	int mx,mi;
	zkw(int mx=-INF,int mi=INF):mx(mx),mi(mi){}
}seg[maxn<<1];
int v[maxn],pre[maxn],d[maxn][2],top[maxn],fa[maxn],son[maxn],dep[maxn],size[maxn],pos[maxn],cnt=0,tot=0,M=1,n;
void add(int,int);
void dfs(int);
void dfs(int,int);
int find(int,int);
void swap(int &x,int &y);
zkw cp(zkw,zkw);
zkw query(int,int);
void updata(int,zkw);
int main()
{
	cls(pre,-1);
	int f,t,m;
	zkw tip;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&f,&t);
		add(f,t);
		add(t,f);
	}
	for(;M<=n+1;M<<=1);
	dep[1]=1;
	dfs(1);
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		tip.mi=tip.mx=v[i];
		updata(pos[i],tip);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&f,&t);
		printf("%d\n",find(f,t));
	}
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
void dfs(int s)
{
	size[s]=1,son[s]=0;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito!=fa[s])
		{
			fa[ito]=s;
			dep[ito]=dep[s]+1;
			dfs(ito);
			if(size[ito]>size[son[s]]) son[s]=ito;
			size[s]+=size[ito];
		}
	}
}
void dfs(int s,int tp)
{
	top[s]=tp;
	pos[s]=++cnt;
	if(son[s]!=0) dfs(son[s],tp);
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito!=son[s]&&ito!=fa[s])
		{
			dfs(ito,ito);
		}
	}
}
int find(int x,int y)
{
	int fx=top[x],fy=top[y];
	zkw tmp;
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy])
		{
			swap(fx,fy),swap(x,y);
		}
		tmp=cp(tmp,query(pos[fx],pos[x]));
		x=fa[fx],fx=top[x];
	}
	if(x==y) return tmp.mx-tmp.mi;
	if(dep[x]>dep[y]) swap(x,y);
	tmp=cp(tmp,query(pos[son[x]],pos[y]));
	return tmp.mx-tmp.mi;
}
void swap(int &x,int &y)
{
	x^=y,y^=x,x^=y;
}
zkw cp(zkw x,zkw y)
{
	zkw ans;
	ans.mx=max(x.mx,y.mx);
	ans.mi=min(x.mi,y.mi);
	return ans;
}
void updata(int pos,zkw val)
{
	seg[pos+=M]=val;
	while(pos>>=1)
	{
		seg[pos]=cp(seg[pos<<1],seg[pos<<1|1]);
	}
}
zkw query(int l,int r)
{
	zkw ans;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans=cp(ans,seg[l^1]); 
		if(r&1) ans=cp(ans,seg[r^1]);
	}
	return ans;
}
