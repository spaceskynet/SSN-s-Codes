#include<iostream>
#include<cstdio>
#include<cstdlib>
#define fill(a,b) fill(a,a+sizeof(a),b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=2e5+10;
struct edge
{
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxn<<1];
int pre[maxn],tot=0,son[maxn]={0},top[maxn]={0},le[maxn]={0},
	dep[maxn]={0},pos[maxn]={0},sz[maxn]={0},fa[maxn]={0},
	sum[maxn<<2]={0},add[maxn<<2]={0},a[maxn],
	n,m,r,p,cnt=0,c=0;
void addedge(int,int);
void dfs(int);
void dfs(int,int);
void update(int,int,int,int,int,int);
void UP(int,int,int);
int query(int,int,int,int,int);
int getsum(int,int);
void PushUP(int);
int main()
{
//	freopen("testdata.in","r",stdin);
	fill(pre,-1);
	scanf("%d%d%d%d",&n,&m,&r,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		addedge(f,t),addedge(t,f);
	}
	dep[r]=1;
	dfs(r);
	dfs(r,r);
	for(int i=1;i<=n;i++)
	{
		update(pos[i],pos[i],a[i],1,n,1);
	}
	while(m--)
	{
		int op,x,y,z;
		scanf("%d",&op);
		if(op==1) scanf("%d%d%d",&x,&y,&z),UP(x,y,z);
		else if(op==2) scanf("%d%d",&x,&y),printf("%d\n",getsum(x,y)%p);
		else if(op==3) scanf("%d%d",&x,&y),update(pos[x],le[x],y,1,n,1);
		else scanf("%d",&x),printf("%d\n",query(pos[x],le[x],1,n,1)%p);
	}
	return 0;
}
void addedge(int from,int to)
{
	e[++tot]=edge(to,pre[from]);pre[from]=tot;
}
void dfs(int s)
{
	sz[s]=1,son[s]=0;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito==fa[s]) continue;
		fa[ito]=s;
		dep[ito]=dep[s]+1;
		dfs(ito);
		if(sz[ito]>sz[son[s]]) son[s]=ito;
		sz[s]+=sz[ito];
	}
}
void dfs(int s,int tp)
{
	top[s]=tp;
	le[s]=pos[s]=++cnt;
	if(son[s]) dfs(son[s],tp),le[s]=max(le[s],le[son[s]]);
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito==fa[s]||ito==son[s]) continue;
		dfs(ito,ito),le[s]=max(le[s],le[ito]);
	}
}
void PushUP(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt]%p;add[rt<<1]%=p;
		add[rt<<1|1]+=add[rt]%p;add[rt<<1|1]%=p;
		sum[rt<<1]+=add[rt]*(m-(m>>1))%p;sum[rt<<1]%=p;
		sum[rt<<1|1]+=add[rt]*(m>>1)%p;sum[rt<<1|1]%=p;
		add[rt]=0;
	}
}
void update(int L,int R,int val,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		add[rt]=(add[rt]+val%p)%p;
		sum[rt]=(sum[rt]+val*(r-l+1)%p)%p;
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m) update(L,R,val,rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return sum[rt]%=p;
	PushDown(rt,r-l+1);
	int m=(l+r)>>1,ret=0;
	if(L<=m) ret=(ret+query(L,R,lson)%p)%p;//L<=m NO! L<=l
	if(R>m) ret=(ret+query(L,R,rson)%p)%p;
	return ret;
}
int getsum(int x,int y)
{
	int fx=top[x],fy=top[y];
	int tmp=0;
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy]) swap(fx,fy),swap(x,y);
		tmp=(tmp+query(pos[fx],pos[x],1,n,1)%p)%p;
		x=fa[fx],fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return tmp=(tmp+query(pos[x],pos[y],1,n,1)%p)%p;
}
void UP(int x,int y,int val)
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy]) swap(fx,fy),swap(x,y);
		update(pos[fx],pos[x],val,1,n,1);
		x=fa[fx],fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(pos[x],pos[y],val,1,n,1);
}
