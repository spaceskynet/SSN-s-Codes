//hdu1754
#include<iostream>
#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=2e5+2e4,INF=~0U>>1;
int Max[maxn<<2],n,m;
void build(int,int,int);
void PushUP(int);
void update(int,int,int,int,int);
int query(int,int,int,int,int);
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);
		while(m--)
		{
			char op[2];
			int l,r;
			scanf("%s%d%d",op,&l,&r);
			if(op[0]=='Q') printf("%d\n",query(l,r,1,n,1));
			else update(l,r,1,n,1);
		}
	}
	return 0;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&Max[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void PushUP(int rt)
{
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void update(int p,int val,int l,int r,int rt)
{
	if(l==r)
	{
		Max[rt]=val;
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
		return Max[rt];
	}
	int m=(l+r)>>1,ret=-INF,tmp;
	if(L<=m) tmp=query(L,R,lson),ret=max(ret,tmp);//由于自己define max函数->三目运算符，query操作会被调用两次 
	if(R>m) tmp=query(L,R,rson),ret=max(ret,tmp);//先开tmp=query，防止TLE 
	return ret;
}
