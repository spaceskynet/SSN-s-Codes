//spaceskynet http://paste.ubuntu.com/25778438/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<deque>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e5+10,INF=~0U>>1;
struct edge
{
	int to,next,val;
	edge(){}
	edge(int to,int next,int val):to(to),next(next),val(val){}
}e[maxn<<3];
int pre[maxn],cnt[maxn],dis[maxn],vis[maxn],tot=0;
int n,m,S;
int read();
void add(int,int,int);
bool SPFA(int);
int main()
{
//	fr();
	mem(pre,-1);
	n=read(),m=read(),S=read();
	for(int i=1,f,t,v;i<=m;i++)
	{
		f=read(),t=read(),v=read();
		add(f,t,v),add(t,f,v);		
	}
	if(SPFA(S)) for(int i=1;i<=n;i++) printf("%d ",dis[i]^INF?dis[i]:-1);
	else printf("Exists Negative Circle!");
	putchar('\n');
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
bool SPFA(int s)
{
	mem(cnt,0),fill(dis,dis+sizeof(dis),INF),mem(vis,0);
	static deque<int> q;
	vis[s]=true,dis[s]=0;
	q.push_back(s);
	while(!q.empty())
	{
		int cur=q.front();q.pop_front();
		vis[cur]=false;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(dis[ito]>dis[cur]+e[i].to)
			{
				dis[ito]=dis[cur]+e[i].to;
				if(!vis[ito]) vis[ito]=true,cnt[cur]++,((q.empty()||dis[ito]>dis[q.front()])?q.push_back(ito):q.push_front(ito));
				if(cnt[ito]>n) return false;
			}
		}
	}
	return true;
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}