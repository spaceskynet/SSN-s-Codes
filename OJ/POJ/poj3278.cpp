#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<queue>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define pii pair<int,int>
#define mk(a,b) make_pair<int,int>(a,b)
#define S first
#define D second
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
bool vis[maxn]={0};
int bfs(int,int);
int read();
int main()
{
//	fr();
	int s,t;
	s=read(),t=read();
	printf("%d\n",bfs(s,t));
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
int bfs(int s,int t)
{
	static queue<pii> q;
	q.push(mk(s,0));
	while(!q.empty())
	{
		pii cur=q.front();q.pop();
		if(cur.S==t) return cur.D;
		if(cur.S<t&&!vis[cur.S+1]) vis[cur.S+1]=true,q.push(mk(cur.S+1,cur.D+1));
		if(cur.S>1&&!vis[cur.S-1]) vis[cur.S-1]=true,q.push(mk(cur.S-1,cur.D+1));
		if(cur.S<=t>>1&&!vis[cur.S<<1]) vis[cur.S<<1]=true,q.push(mk(cur.S<<1,cur.D+1));
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
