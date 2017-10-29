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
const int maxn=1e5+10,maxm=2e5+10,INF=~0U>>1;
struct edge
{
	int to,next,val;
	edge(){}
	edge(int to,int next,int val):to(to),next(next),val(val){}
}e[maxm<<1];
int pre[maxn],dis[2][maxn],tot=0;
bool vis[maxn];
int read();
int main()
{
//	fr();
	mem(pre,-1);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
bool SPFA(int s)
{
	static deque<int> q;
	mem(vis,0),fill(dis,dis+sizeof(dis),INF);
	vis[s]=true,dis[0][s]=dis[1][s]=0;
	q.push_back(s);
	while(!q.empty())
	{
		int cur=q.front();q.pop_front();
		vis[cur]=false;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int &ito=e[i].to,&zdto=dis[0][ito],&zds=dis[0][s],&val=e[i].val,&cdto=dis[1][ito],&cds=dis[1][s];
			if(zdto>zds+val) 
			{
				cdto=zdto,zdto=zds+val;
				if(!vis[ito]) vis[ito]=true,cnt[cur]++,((q.empty()||dis[0][ito]>dis[0][q.front()])?q.push_back(ito):q.push_front(ito));
			}
			else if(cdto>zds+val&&zdto<zds+val)
			{
				cdto=zds+val;
				if(!vis[ito]) vis[ito]=true,cnt[cur]++,((q.empty()||dis[0][ito]>dis[0][q.front()])?q.push_back(ito):q.push_front(ito));
			}
			if(cdto>cds+val)
			{
				cdto=cds+val;
				if(!vis[ito]) vis[ito]=true,cnt[cur]++,((q.empty()||dis[0][ito]>dis[0][q.front()])?q.push_back(ito):q.push_front(ito));
			}
			if(cnt[ito]>n) return false;
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