//spaceskynet 2017-09-10 HNOI2011
#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=1e5+10;
struct edge
{
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxn<<1];
int pre[maxn],tot=-1,son[maxn]={0},fa[maxn]={0},sz[maxn]={0},top[maxn]={0},
	dep[maxn]={0},pos[maxn],cnt=0,lcol=-1,rcol=-1,n,m,a[maxn],
	ch[maxn<<2],q[maxn<<2]={0},lbd[maxn<<2]={0},rbd[maxn<<2]={0};
void add(int,int);
void dfs(int);
void dfs(int,int);
void update(int,int,int,int,int,int);
int query(int,int,int,int,int);
void UP(int,int,int);
int getans(int,int);
void PushUP(int);
void PushDown(int);
int main()
{
	//freopen("paint.in","r",stdin);
	cls(pre,-1),cls(ch,-1);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t),add(t,f);
	}
	dep[1]=1;
	dfs(1);
	dfs(1,1);
	for(int i=1;i<=n;i++) update(pos[i],pos[i],a[i],1,n,1);
	while(m--)
	{
		char op[2];
		int x,y,z;
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='C') scanf("%d",&z),UP(x,y,z);
		else printf("%d\n",getans(x,y));
	}
	return 0;
}
void add(int from,int to)
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
	pos[s]=++cnt;
	if(son[s]) dfs(son[s],tp);
	for(int i=pre[s];~i;i=e[i].next) 
	{
		int &ito=e[i].to;
		if(ito==fa[s]||ito==son[s]) continue;
		dfs(ito,ito);
	}
}
void PushUP(int rt)
{
	q[rt]=q[rt<<1]+q[rt<<1|1]-(rbd[rt<<1]==lbd[rt<<1|1]);
	lbd[rt]=lbd[rt<<1],rbd[rt]=rbd[rt<<1|1];
}
void PushDown(int rt)
{
	if(~ch[rt])
	{
		q[rt<<1]=q[rt<<1|1]=1,
		lbd[rt<<1]=lbd[rt<<1|1]=ch[rt],
		rbd[rt<<1]=rbd[rt<<1|1]=ch[rt],
		ch[rt<<1]=ch[rt<<1|1]=ch[rt],
		ch[rt]=-1;
	}
}
void update(int L,int R,int val,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		q[rt]=1,lbd[rt]=rbd[rt]=val;
		ch[rt]=val;
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m) update(L,R,val,rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L==l) lcol=lbd[rt];
	if(R==r) rcol=rbd[rt];
	if(L<=l&&r<=R) return q[rt];
	PushDown(rt);
	int m=(l+r)>>1,ret=0,tl=-1,tr=-1;
	if(L<=m) ret+=query(L,R,lson),tl=rbd[rt<<1];
	if(R>m) ret+=query(L,R,rson),tr=lbd[rt<<1|1];
	ret-=(tl==tr&&~tl);
	//PushUP(rt);
	return ret;
}
void UP(int x,int y,int val)
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
		update(pos[fx],pos[x],val,1,n,1);
		x=fa[fx],fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(pos[x],pos[y],val,1,n,1);
}
int getans(int x,int y)
{
	int fx=top[x],fy=top[y],tl=-1,tr=-1,ret=0;
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy),swap(tl,tr);
		ret+=query(pos[fx],pos[x],1,n,1);
		ret-=(tl==rcol);
		tl=lcol;
		x=fa[fx],fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y),swap(tl,tr);
	ret+=query(pos[x],pos[y],1,n,1);//lcol-->lbd[pos[x]->mid] rcol-->rbd[mid<--pos[y]]
	ret-=(tl==lcol&&~tl)+(tr==rcol&&~tr);//No !tl==rcol && tr==lcol
	return ret;
}
