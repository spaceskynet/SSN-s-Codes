#include<iostream>
#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll sum[maxn<<2],add[maxn<<2];
int n,q;
void build(int,int,int);
void PushUP(int);
void PushDown(int,int);
void update(int,int,int,int,int,int);
ll query(int,int,int,int,int);
int main()
{
	char op[5];
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while(q--)
	{
		int a,b,c;
		scanf("%s",op);
		if(op[0]=='Q') scanf("%d%d",&a,&b),printf("%lld\n",query(a,b,1,n,1));
		else scanf("%d%d%d",&a,&b,&c),update(a,b,c,1,n,1);
	}
	return 0;
}
void build(int l,int r,int rt)
{
	add[rt]=0;
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int L,int R,int val,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		add[rt]+=val;
		sum[rt]+=1ll*(r-l+1)*val;
		return;//!!
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m) update(L,R,val,rson);
	PushUP(rt);
}
void PushUP(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
	if(add[rt])
	{
		add[rt<<1]+=add[rt],add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(m-(m>>1)),sum[rt<<1|1]+=add[rt]*(m>>1);
		add[rt]=0;
	}
}
ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	ll ret=0;
	if(L<=m) ret+=query(L,R,lson);
	if(R>m) ret+=query(L,R,rson);
	return ret;
}
