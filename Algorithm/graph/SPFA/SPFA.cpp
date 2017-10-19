#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e6,INF=2147483647;
struct edge
{
	int to,next,val;
}e[5*maxn];
int pre[maxn],cnt[maxn]={0},dis[maxn],tot=0;
bool vis[maxn]={0};
void addedge(int,int,int);
void out(int);
bool SPFA(int,int);
int main()
{
	//cls(dis,INF),
	cls(pre,-1);
	int n,m,s,f,t,v;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f,&t,&v);
		addedge(f,t,v);
	}
	if(SPFA(s,n)) out(n);
	return 0;
}
void addedge(int from,int to,int val)
{
	e[++tot].to=to;e[tot].val=val;e[tot].next=pre[from];pre[from]=tot;
}
void out(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
}
bool SPFA(int s,int n)
{
	vis[s]=1;
	cnt[s]=1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(dis[ito]>dis[cur]+e[i].val)
			{
				dis[ito]=dis[cur]+e[i].val;
				if(!vis[ito])
				{
					cnt[cur]++;
					q.push(ito);
					vis[ito]=1;
				}
				if(cnt[ito]>n) return false;
			}
		}
	}
	return true;
}