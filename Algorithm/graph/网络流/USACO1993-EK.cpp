//EK
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxm=5e3+10,maxn=1e3+10;
struct edge
{
	int from,to,next,cap;
	edge(){}
}e[maxm<<1];
int pre[maxn],from[maxm],tot=-1,S,T,n,m;
bool vis[maxm];
void add(int,int,int);
bool bfs();
int EK();
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
	printf("%d\n",EK());
	return 0;
}
void add(int from,int to,int cap)
{
	e[++tot].to=to;e[tot].from=from;e[tot].cap=cap;e[tot].next=pre[from];pre[from]=tot;
}
bool bfs()
{
	static queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(from,0,sizeof(from));
	vis[S]=true;
	q.push(S);
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!e[i].cap||vis[ito]) continue;
			vis[ito]=true;
			from[ito]=i;
			q.push(ito);
		}
	}
	return vis[T];
}
int EK()
{
	int ans=0;
	while(bfs())
	{
		int mi=~0U>>1;
		for(int i=T;i!=S;i=e[from[i]].from) mi=min(e[from[i]].cap,mi);
		for(int i=T;i!=S;i=e[from[i]].from)
		{
			e[from[i]].cap-=mi;
			e[from[i]^1].cap+=mi;
		}
		ans+=mi;
	}
	return ans;
}

