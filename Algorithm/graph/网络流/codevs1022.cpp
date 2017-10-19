#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e4+100,INF=~0U>>1,
		dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct edge
{
	int to,next,cap;
	edge(){}
	edge(int to,int next,int cap):to(to),next(next),cap(cap){}
}e[maxn];
int pre[maxn],sub[maxn],dep[maxn],tot=-1,S,T,n,m,t,cntx=0,cnty;
int mark[101][101]={0};
void add(int,int,int);
bool bfs();
int dfs(int,int);
int Dinic();
bool check(int,int);
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	int x,y;
	while(t--)
	{
		scanf("%d%d",&x,&y);
		mark[x][y]=-1;
	}
	cnty=(n*m+1)/2,S=0,T=n*m+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)//打成n 
		{
			if(~mark[i][j]) 
			{
				if((i+j)%2) mark[i][j]=++cnty;
				else mark[i][j]=++cntx;
			}
		}
	}
	memset(pre,-1,sizeof(pre));//记得初始化 
	for(int i=1;i<=cntx;i++) add(S,i,1),add(i,S,0);
	for(int i=cntx+1;i<=n*m;i++) add(i,T,1),add(T,i,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!check(i,j)) continue; 
			for(int k=0;k<4;k++)
			{
				if(check(i+dx[k],j+dy[k]))
				{
					add(mark[i][j],mark[i+dx[k]][j+dy[k]],1);
					add(mark[i+dx[k]][j+dy[k]],mark[i][j],0);
				}
			}
		}
	}
	printf("%d\n",Dinic());
	return 0;
}
bool check(int x,int y)
{
	return ~mark[x][y]&&x>=1&&x<=n&&y>=1&&y<=m;
}
void add(int from,int to,int cap)
{
	e[++tot]=edge(to,pre[from],cap);pre[from]=tot;
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
	memset(dep,-1,sizeof(dep));
	dep[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!e[i].cap||~dep[ito]) continue;
			dep[ito]=dep[cur]+1;
			q.push(ito);
		}
	}
	return ~dep[T];
}
int dfs(int now,int maxflow)
{
	if(now==T||!maxflow) return maxflow;
	int ans=0,tmp;
	for(int &i=sub[now];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!e[i].cap||dep[ito]!=dep[now]+1) continue;
		tmp=dfs(ito,min(maxflow,e[i].cap));
		e[i].cap-=tmp,e[i^1].cap+=tmp;
		ans+=tmp,maxflow-=tmp;
		if(!maxflow) break;
	}
	if(!ans) dep[now]=-1;
	return ans;
}
