//spaceskynet 2017-08-27 mincostflow(SPFA+SLF)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<deque>
using namespace std;
const int maxn=1e4+10,maxm=1e5+10,INF=~0U>>1;
struct edge
{
	int to,next,cap,w;
	edge(){}
	edge(int to,int next,int cap,int w):to(to),next(next),cap(cap),w(w){}
}e[maxm];
int pre[maxn],sub[maxn],dis[maxn],tot=-1,allw=0,n,m,S,T;
bool visb[maxn]={0},visd[maxn]={0};
void add(int,int,int,int);
int dfs(int,int);
bool SPFA();
int mcf();
int main()
{
	memset(pre,-1,sizeof(pre));
	scanf("%d%d%d%d",&n,&m,&S,&T);
//	S=1,T=n;
	for(int i=1;i<=m;i++)
	{
		int f,t,c,w;
		scanf("%d%d%d%d",&f,&t,&c,&w);
		add(f,t,c,w);
		add(t,f,0,-w);
	}
	int ans=mcf();
	printf("%d %d\n",ans,allw);
	return 0;
}
void add(int from,int to,int cap,int w)
{
	e[++tot]=edge(to,pre[from],cap,w);pre[from]=tot;
}
bool SPFA()
{
//	fill(dis,INF,sizeof(dis));
	static deque<int> q;
	for(int i=1;i<=n;i++) dis[i]=INF,visb[i]=false;
	visb[T]=true,dis[T]=0;
	q.push_back(T);
	while(!q.empty())
	{
		int cur=q.front();q.pop_front();
		visb[cur]=false;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!e[i^1].cap||dis[ito]<=dis[cur]-e[i].w) continue;
			dis[ito]=dis[cur]-e[i].w;
			if(!visb[ito]) visb[ito]=true,((q.empty()||dis[ito]>dis[q.front()])?q.push_back(ito):q.push_front(ito));
		}
	}
	return dis[S]^INF;
}
int mcf()
{
	int ans=0;
	while(SPFA()) ans+=dfs(S,INF);
	return ans;
}
int dfs(int now,int maxflow)
{
	if(visd[now]) return 0;
	if(now==T||!maxflow) return allw+=dis[S]*maxflow,maxflow;
	visd[now]=true;
	int ans=0,tmp;
	for(int i=pre[now];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!e[i].cap||dis[ito]!=dis[now]-e[i].w) continue;
		tmp=dfs(ito,min(maxflow,e[i].cap));
		e[i].cap-=tmp,e[i^1].cap+=tmp;
		ans+=tmp,maxflow-=tmp;
		if(!maxflow) break;
	}
	if(!ans) dis[now]=INF;
	visd[now]=false;
	return ans;
}
