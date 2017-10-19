#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=5e4+10,INF=~0U>>1;
typedef long long ll;
struct seg
{
	int h,l,r,s;
	seg(){}
	seg(int h,int l,int r,int s):h(h),l(l),r(r),s(s){}
	bool operator < (const seg &a) const{
		return this->h<a.h;
	}
}L[maxn<<3];
int sum[maxn<<4],cnt[maxn<<4],n,m,lbd=INF,rbd=-INF;
void update(int,int,int,int,int,int);
void PushUP(int,int,int);
int merge(int);
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		cls(sum,0),cls(cnt,0);
		m=0;
		for(int i=1;i<=n;i++)
		{
			int x1,y1,x2,y2,x3,y3,x4,y4;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
			L[++m]=seg(y1,x1,x3,-1);
			L[++m]=seg(y2,x1,x3,1);
			L[++m]=seg(y1,x4,x2,-1);
			L[++m]=seg(y2,x4,x2,1);
			L[++m]=seg(y1,x3,x4,-1);
			L[++m]=seg(y3,x3,x4,1);
			L[++m]=seg(y4,x3,x4,-1);
			L[++m]=seg(y2,x3,x4,1);
			lbd=min(x1,lbd);
			rbd=max(x2,rbd);
		}
		sort(L+1,L+m+1);
		ll ans=0;
		for(int i=1;i<m;i++)
		{
			int l=L[i].l,r=L[i].r-1;
			if(l<=r) update(l,r,L[i].s,lbd,rbd,1);
			ans+=1ll*sum[1]*(L[i+1].h-L[i].h);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
void update(int L,int R,int val,int l,int r,int rt)
{
//	if(L>R) return;
	if(L<=l&&r<=R)
	{
		cnt[rt]+=val;
		PushUP(rt,l,r);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m) update(L,R,val,rson);
	PushUP(rt,l,r);
}
void PushUP(int rt,int l,int r)
{
	if(cnt[rt]) sum[rt]=r+1-l;
	else if(l==r) sum[rt]=0;
	else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
