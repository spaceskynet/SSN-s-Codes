//∆Ô øπ≤¥Ê
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxl=201,maxn=maxl*maxl,maxm=maxn<<4,INF=~0U>>1,
		  dx[8]={1,1,2,2,-1,-1,-2,-2},
		  dy[8]={2,-2,1,-1,2,-2,1,-1};
struct edge
{
	int to,next,cap;
	edge(){}
	edge(int to,int next,int cap):to(to),next(next),cap(cap){}	
}e[maxm];
int pre[maxn],sub[maxn],dis[maxn],map[maxl][maxl]={0},tot=-1,S,T,n,m,cnt=0;
void add(int,int,int);
int dfs(int,int);
bool bfs();
int Dinic();
bool check(int,int);
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);S=0,T=n*n+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][y]=-1;
	}
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(~map[i][j])
			{
				map[i][j]=++cnt;
				if((i+j)%2) add(cnt,T,1),add(T,cnt,0);
				else add(S,cnt,1),add(cnt,S,0);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(~map[i][j]&&!((i+j)%2))
			{
				for(int k=0;k<8;k++)
				{
					int tx=i+dx[k],ty=j+dy[k];
					if(check(tx,ty)) add(map[i][j],map[tx][ty],INF),add(map[tx][ty],map[i][j],0);
				}
			}
		}
	}
	printf("%d\n",n*n-m-Dinic());
	return 0;
}
void add(int from,int to,int cap)
{
	e[++tot]=edge(to,pre[from],cap),pre[from]=tot;
}
bool check(int x,int y)
{
	return ~map[x][y]&&x>=1&&x<=n&&y>=1&&y<=n;
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
		e[i].cap-=tmp,e[i^1].cap+=tmp;
		ans+=tmp,maxflow-=tmp;
		if(!maxflow) break;
	}
	if(!ans) dis[now]=-1;
	return ans;
}
