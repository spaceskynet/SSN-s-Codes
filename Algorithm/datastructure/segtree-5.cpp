#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=2e3+10;
typedef double db;
struct seg
{
	db h,l,r;
	int s;
	seg(){}
	seg(db h,db l,db r,int s):h(h),l(l),r(r),s(s){}
	bool operator < (const seg &a) const{
		return this->h<a.h;
	}
}line[maxn];
int cnt[maxn<<2]={0},k=1;
db sum[maxn<<2],x[maxn];
void update(int,int,int,int,int,int);
void PushUP(int,int,int);
int merge(db);
int main()
{
	int n,t=0;
	while(~scanf("%d",&n)&&n)
	{
		int m=0;
		while(n--)
		{
			db a,b,c,d;
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			x[++m]=a,line[m]=seg(b,a,c,1);
			x[++m]=c,line[m]=seg(d,a,c,-1);
		}
		sort(x+1,x+m+1);
		sort(line+1,line+m+1);
		k=1;
		for(int i=2;i<=m;i++)
		{
			if(x[i]!=x[i-1]) x[++k]=x[i];
		}
		cls(cnt,0),cls(sum,0);
		db ans=0;
		for(int i=1;i<=m;i++)
		{
			int l=merge(line[i].l),r=merge(line[i].r)-1;
			if(l<=r) update(l,r,line[i].s,1,k,1);
			ans+=sum[1]*(line[i+1].h-line[i].h);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",++t,ans);
	}
	return 0;
}
void update(int L,int R,int val,int l,int r,int rt)
{
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
	if(cnt[rt]) sum[rt]=x[r+1]-x[l];
	else if(l==r) sum[rt]=0;
	else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int merge(db mid)
{
	int l=1,r=k,m;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(x[m]==mid) return m;
		if(x[m]<mid) l=m+1;
		else r=m-1;
	}
	return -1;
}
