#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5,INF=(1<<30);
struct edge
{
	int to,from,val;
	bool operator < (const edge &a) const
	{
		return this->val<a.val;
	}
}e[maxn*maxn];
int n,ans=0,x,pre[maxn],tot=0;
void add(int,int,int);
int find(int);
int main()
{
	scanf("%d",&n);
	ios::sync_with_stdio(false);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if(i<=j)
			{
				add(i-1,j,x);
			}
		}
	}
	for(int i=1;i<=n;i++) pre[i]=i;
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		int x=find(e[i].from),y=find(e[i].to);
		if(x!=y)
		{
			pre[x]=y;
			ans+=e[i].val;
		}
	}
	printf("%d",ans);
	return 0;
}
void add(int from,int to,int val)
{
	e[++tot].to=to;e[tot].from=from;e[tot].val=val;
}
int find(int x)
{
	if(pre[x]==x) return pre[x];
	else return pre[x]=find(pre[x]);
}
