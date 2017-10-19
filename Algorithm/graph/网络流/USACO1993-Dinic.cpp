//Dinic
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxm=5e3+10,maxn=1e3+10,INF=~0U>>1;
struct edge
{
	int to,next,cap;
	edge(){}
}e[maxm<<1];
int pre[maxn],sub[maxm],tot=-1,S,T,n,m;
int dis[maxn];
void add(int,int,int);
bool bfs();
int dfs(int,int);
int Dinic();
int main()
{
	scanf("%d%d",&n,&m);
	S=1,T=n;
	int f,t,c;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f,&t,&c);
		add(f,t,c);
		add(t,f,0);
	}
	printf("%d\n",Dinic());
	return 0;
}
void add(int from,int to,int cap)
{
	e[++tot].to=to;e[tot].cap=cap;e[tot].next=pre[from];pre[from]=tot;
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
	return ~dis[T];//汇点是否在分层网络中，如不在，Dinic结束 
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

