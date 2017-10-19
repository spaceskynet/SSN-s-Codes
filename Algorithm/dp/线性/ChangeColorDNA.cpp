#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=102,INF=(1<<30);
int n,t,f[maxn][maxn]={0},dis[maxn];
bool vis[maxn]={0};
void SPFA(int);
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		char c[maxn];
		scanf("%d",&n);
		for(int i=1;i<=n;i++) vis[i]=0,dis[i]=INF;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c+1);
			int x=0;
			for(int j=1;j<=n;j++)
			{
				if(c[j]=='Y') f[i][j]=x++;
				else f[i][j]=INF;
			}
		}
		SPFA(1);
		if(dis[n]==INF) printf("-1\n");
		else printf("%d\n",dis[n]);
	}
	return 0;
}
void SPFA(int s)
{
	vis[s]=1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>dis[cur]+f[cur][i])
			{
				dis[i]=dis[cur]+f[cur][i];
				if(!vis[i])
				{
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
}
