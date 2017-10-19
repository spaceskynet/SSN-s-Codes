//2017-03-21 UnionFind+kruskal by:spaceskynet
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=4e5+10;
struct edge
{
	int from,to,val;
	bool operator < (const edge &a) const
	{
		return this->val<a.val;
	}
}e[maxn];
int find(int);
void connect(int,int);
bool cmp(edge,edge);
int pre[5010],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].val);
		//e[i+1].from=e[i].to,e[i+1].to=e[i].from,e[i+1].val=e[i].val;
	}
	for(int i=1;i<=n;i++) pre[i]=i;
	sort(e+1,e+m+1,cmp);
	int step=0,ans=0;
	for(int i=1;i<=m&&step<n;i++)
	{
		int x=e[i].from,y=e[i].to;
		if(find(x)!=find(y))
		{
			connect(x,y);
			step++;
			ans+=e[i].val;
		}
	}
	printf("%d\n",ans);
	return 0;
}
bool cmp(edge a,edge b){return a<b;}
int find(int x)
{
	if(pre[x]==x) return pre[x];
	else return pre[x]=find(pre[x]);
}
void connect(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		pre[fx]=fy;
	}
}
