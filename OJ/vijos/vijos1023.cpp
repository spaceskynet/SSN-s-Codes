//spaceskynet 2017-08-06 vijos1023 强连通分量+缩点 
#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=205;
struct edge
{
	int to,next;
}e[maxn*maxn];
int pre[maxn]={0},tot=0,
	n,m,f,t,
	head[maxn]={0},dfsClock=0,cnt=0,In[maxn]={0},
	lowlink[maxn],sccno[maxn],sccCnt=0,
	stack[maxn]={0},top=0;
void add(int,int);
void dfs(int);
void findScc();
int main()
{
	scanf("%d",&n);
	cls(pre,-1);
	for(int i=1;i<=n;i++)
	{
		while(true)
		{
			scanf("%d",&m);
			if(m==0) break;
			add(i,m);
		}
	}
	findScc();
	for(int j=1;j<=n;j++)
	{
		for(int i=pre[j];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(ito==-1) continue;
			if(sccno[j]!=sccno[ito]) In[sccno[ito]]++;
		}
	}
	for(int i=1;i<=sccCnt;i++)
	{
		if(In[i]==0) cnt++;
//		printf("%d\n",In[i]);
	}
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
