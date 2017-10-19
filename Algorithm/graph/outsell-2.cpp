#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
struct edge
{
	int to,next;
}e[maxn<<1];
queue<char> q;
int pre[maxn<<1],n,x,a[maxn],b[maxn],tot=0;
bool arr[maxn]={0},vis[maxn]={0};
void dfs(int);
void add(int,int);
int main()
{
	memset(pre,-1,sizeof(pre));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[i]=i+x;
		if(i+x<0||i+x>=n) continue;
		add(i+x,i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		b[i]=x+i;
		if(i+x<0||i+x>=n) continue;
		add(i+x,i);
	}
	dfs(n-1);
	if(!arr[0])
	{
		printf("No solution!");
		return 0;
	}
	memset(vis,false,sizeof(vis));
	int t=0;
	while(t!=n-1)
	{
		vis[t]=true;
		if(vis[a[t]]&&arr[a[t]])
		{
			printf("Infinity!");
			return 0;
		}
		else if(a[t]>=0&&a[t]<n)
		{
			if(arr[a[t]]&&!vis[a[t]])
			{
				q.push('a');
				t=a[t];
			}
		}
		else if(b[t]>=0&&b[t]<n)
		{
			if(arr[b[t]]&&!vis[b[t]])
			{	
				q.push('b');
				t=b[t];
			}
		}
	}
	while(!q.empty())
	{
		printf("%c",q.front());
		q.pop();
	}
	return 0;
}
void dfs(int s)
{
	arr[s]=true;
	vis[s]=true;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!vis[ito]) dfs(ito);
	}
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
