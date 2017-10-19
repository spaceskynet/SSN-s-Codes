//spaceskynet 2017-08-06 POJ3180 强连通分量
#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e4+10;
struct edge
{
	int to,next;
}e[maxn*5];
int pre[maxn]={0},tot=0,
	n,m,f,t,
	head[maxn]={0},dfsClock=0,ans[maxn]={0},
	lowlink[maxn],sccno[maxn],sccCnt=0,
	stack[maxn]={0},top=0;
void add(int,int);
void dfs(int);
void findScc();
int main()
{
	scanf("%d%d",&n,&m);
	cls(pre,-1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&f,&t);
		add(f,t);
	}
	findScc();
	for(int i=1;i<=n;i++) ans[sccno[i]]++;
	int cnt=0;
	for(int i=1;i<=n;i++) if(ans[i]>1) cnt++;
	printf("%d\n",cnt);
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
void dfs(int s)
{
	head[s]=lowlink[s]=++dfsClock;
	stack[++top]=s;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!head[ito])
		{
			dfs(ito);
			lowlink[s]=min(lowlink[ito],lowlink[s]);
		}
		else if(!sccno[ito]) lowlink[s]=min(head[ito],lowlink[s]);
	}
	if(lowlink[s]==head[s])
	{
		sccCnt++;
		while(true)
		{
			int x=stack[top--];
			sccno[x]=sccCnt;
			if(x==s) break;
		}
	}
}
void findScc()
{
	dfsClock=sccCnt=0;
	cls(head,0),cls(sccno,0);
	for(int i=1;i<=n;i++)
	{
		if(!head[i]) dfs(i);
	}
}
