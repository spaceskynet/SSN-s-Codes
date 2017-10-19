#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=110,INF=~0U>>1;
struct edge
{
	int to,next,cap;
}e[maxn*maxn];
int pre[maxn<<1],dis[maxn],sub[maxn<<1],n,m,tot=-1,S,T;//tot应设为-1，add时++tot 
void add(int,int,int);
bool bfs();
int dfs(int,int);
int Dinic();
int main()
{
	int f,t;
	memset(pre,-1,sizeof(pre));
	scanf("%d%d",&m,&n);S=0,T=n+1;
	while(scanf("%d%d",&f,&t))
	{
	    if(f==-1&&t==-1) break;
	    add(f,t,1),add(t,f,0);
	}
	for(int i=1;i<=m;i++) add(S,i,1),add(i,S,0);
	for(int i=m+1;i<=n;i++) add(i,T,1),add(T,i,0);
	printf("%d\n",Dinic());
	return 0;
}
void add(int from,int to,int cap)
{
	e[++tot].to=to;e[tot].cap=cap;e[tot].next=pre[from];pre[from]=tot;
}
int Dinic()
{
	int ans=0;
	while(bfs())
	{
		memcpy(sub,pre,sizeof(pre));
		ans+=dfs(S,INF);
	}
	return ans;
}
bool bfs()
{
	static queue<int> q;
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	q.push(S);
	while(!q.empty())	
	{
		int cur=q.front();q.pop();
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!e[i].cap||~dis[ito]) continue;
			dis[ito]=dis[cur]+1;
			q.push(ito);
		}
	}
	return ~dis[T];
}
int dfs(int now,int maxflow)
{
	if(now==T||!maxflow) return maxflow;
	int ans=0,tmp;
	for(int &i=sub[now];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!e[i].cap||dis[ito]!=dis[now]+1) continue;
		tmp=dfs(ito,min(maxflow,e[i].cap));
		e[i].cap-=tmp;
		e[i^1].cap+=tmp;
		ans+=tmp,maxflow-=tmp;
		if(!maxflow) break;
	}
	if(!ans) dis[now]=-1;
	return ans;
}
