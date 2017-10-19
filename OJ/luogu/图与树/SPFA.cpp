#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int maxn=1e5+10;
const int INF=2147483647;
struct Edge
{
	int to,next,val;
}e[5*maxn];
int pre[maxn],tot=0,dis[maxn];
bool vis[maxn]={0};
void SPFA(int,int);
void addedge(int,int,int);
void out(int);
int main()
{
	memset(pre,-1,sizeof(pre));
	int n,f,t,v,m,s,end;
	scanf("%d%d%d%d",&n,&m,&s,&end);
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		vis[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f,&t,&v);
		addedge(f,t,v);
		addedge(t,f,v);
	}
	SPFA(s,n);
	cout<<dis[end]<<endl;
	return 0;
}
void addedge(int from,int to,int val)
{
	e[++tot].to=to;e[tot].val=val;e[tot].next=pre[from];pre[from]=tot;
}
void SPFA(int s,int n)
{
	dis[s]=0;
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=pre[cur];i!=-1;i=e[i].next)
		{
			int ito=e[i].to;
			if(dis[ito]>dis[cur]+e[i].val)
			{
				dis[ito]=dis[cur]+e[i].val;
				if(!vis[ito])
				{
					q.push(ito);
					vis[ito]=1;
				}
			}
		}
	}
}