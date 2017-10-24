#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
typedef int INT[maxn];
struct edge
{
	int to,next,from;
	edge(){}
	edge(int to,int next,int from):to(to),next(next),from(from){}
}e[(maxn<<1)+maxn];
INT pre,low,dfn,stack,sccno,in,sz;
bool ins[maxn];
int tot=0,top=0,n,m,sccCnt=0,dfsClock=0;
int read();
void findScc();
void makeScc();
void add(int,int);
void dfs(int);
int main()
{
//	fr();
	mem(pre,-1);
	n=read(),m=read();
	for(int i=1,f,t;i<=m;i++)
	{
		f=read(),t=read();
		add(f,t);
	}
	findScc();
	makeScc();
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to)
{
	e[++tot]=edge(to,pre[from],from);pre[from]=tot;
}
void makeScc()
{
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		int ito=e[i].to,ifr=e[i].from;
		if(sccno[ifr]^sccno[ito]) in[sccno[ito]]++;
	}
	for(int i=1;i<=sccCnt;i++) if(!in[i]) ans++;
	for(int i=1;i<=n;i++)
	{
		if(sz[sccno[i]]==1&&!in[sccno[i]])
		{
			bool flag=true;
			for(int j=pre[i];~j;j=e[j].next)
			{
				int jto=e[j].to;
				if(in[sccno[jto]]<=1){flag=false;break;}
			}
			if(flag){ans--;break;}
		}
	}
	db Ans=1.0*(n-ans)/n;
	printf("%.6f\n",Ans);
}
void findScc()
{
	dfsClock=sccCnt=0;
	mem(low,0),mem(sccno,0),mem(dfn,0),mem(ins,0),mem(stack,0),mem(sz,0),top=0;
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
}
void dfs(int s)
{
	dfn[s]=low[s]=++dfsClock;
	ins[stack[++top]=s]=true;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!dfn[ito]) dfs(ito),low[s]=min(low[s],low[ito]);
		else if(ins[ito]) low[s]=min(dfn[ito],low[s]);
	}
	if(low[s]^dfn[s]) return;
	sccCnt++;
	while(true)
	{
		int x=stack[top--];
		ins[x]=false;
		sccno[x]=sccCnt;
		sz[sccCnt]++;
		if(x==s) break;
	}
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}