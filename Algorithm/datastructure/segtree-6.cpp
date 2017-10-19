#include<iostream>
#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define plus k,1
#define times 0,k
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll sum[maxn<<2],add[maxn<<2],mul[maxn<<2],mod,n,m;
void build(int,int,int);
void update(int,int,int,int,int,int,int);
void PushUP(int);
void PushDown(int,int);
ll query(int,int,int,int,int);
int main()
{
	scanf("%lld%lld%lld",&n,&m,&mod);
	build(1,n,1);
	while(m--)
	{
		int op,x,y,k;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) scanf("%d",&k),update(x,y,times,1,n,1);
		else if(op==2) scanf("%d",&k),update(x,y,plus,1,n,1);
		else printf("%lld\n",query(x,y,1,n,1));
	}
	return 0;
}
void build(int l,int r,int rt)
{
	add[rt]=0,mul[rt]=1;
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
void PushUP(int rt)
{
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%mod;
}
void PushDown(int rt,int m)
{
	if(add[rt]||mul[rt]!=1)
	{
		//lson
		sum[rt<<1]=((sum[rt<<1]*mul[rt])+(1ll*(m-(m>>1))*add[rt]))%mod;
		mul[rt<<1]=(mul[rt<<1]*mul[rt])%mod;
		add[rt<<1]=(add[rt<<1]*mul[rt]+add[rt])%mod;
		//rson
		sum[rt<<1|1]=((sum[rt<<1|1]*mul[rt])+(1ll*(m>>1)*add[rt]))%mod;
		mul[rt<<1|1]=(mul[rt<<1|1]*mul[rt])%mod;
		add[rt<<1|1]=(add[rt<<1|1]*mul[rt]+add[rt])%mod;
		//clear
		add[rt]=0,mul[rt]=1;
	}
}
ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return sum[rt]%mod;
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	ll ret=0;
	if(L<=m) ret+=query(L,R,lson)%mod;
	if(R>m) ret+=query(L,R,rson)%mod;
	return ret%mod;
}
void update(int L,int R,int Add,int Mul,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		sum[rt]=((sum[rt]*Mul)+(1ll*(r-l+1)*Add))%mod;
		mul[rt]=(mul[rt]*Mul)%mod;
		add[rt]=(add[rt]*Mul+Add)%mod;
		return;		
	}
	PushDown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,Add,Mul,lson);
	if(R>m) update(L,R,Add,Mul,rson);
	PushUP(rt);
}
