//BIT+差分 --> 区间修改+单点查询
#include<iostream>
#include<cstdio>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll sum[maxn]={0},x=0,y=0;
int n,q;
void update(int,int);
void UP(int,int,int);
ll query(int);
//ll getsum(int,int);
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		y=x;
		scanf("%lld",&x);
		update(i,x-y);
	}
	scanf("%d",&q);
	while(q--)
	{
		int a,b,c;
		scanf("%d",&c);
		if(c==2) scanf("%d",&a),printf("%lld\n",query(a));
		else scanf("%d%d%d",&a,&b,&c),UP(a,b,c);
	}
	return 0;
}
void update(int p,int val)
{
	for(int i=p;i<=n;i+=lowbit(i))
	{
		sum[i]+=val;
	}
}
ll query(int p)
{
	ll ret=0;
	for(int i=p;i>0;i-=lowbit(i))
	{
		ret+=sum[i];
	}
	return ret;
}
//ll getsum(int l,int r)
//{
//	ll R=query(r),L=query(l);
//	return (r-l)*L+R;
//}
void UP(int l,int r,int val)
{
	update(l,val);
	update(r+1,-val);
}

