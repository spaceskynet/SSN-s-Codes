#include<iostream>
#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=6e4+10;
char op[10];
int sum[maxn<<2],n;
void PushUP(int);
void build(int,int,int);
void update(int,int,int,int,int);
int query(int,int,int,int,int);
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case %d:\n",i);
		scanf("%d",&n);
		build(1,n,1);
		while(scanf("%s",op))
		{
			if(op[0]=='E') break;
			int l,r;
			scanf("%d%d",&l,&r);
			if(op[0]=='Q') printf("%d\n",query(l,r,1,n,1));
			else if(op[0]=='A') update(l,r,1,n,1);
			else update(l,-r,1,n,1);
		}
	}
	return 0;
}
void PushUP(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int val,int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]+=val;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) update(p,val,lson);
	else update(p,val,rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return sum[rt];
	}
	int m=(l+r)>>1,ret=0;
	if(L<=m) ret+=query(L,R,lson);
	if(R>m) ret+=query(L,R,rson);
	return ret;
}
