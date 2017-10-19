//BIT+差分 --> 区间修改+区间查询
/*
a[]->past,add[i]->[i,n] all added;
sum[i]=a[1]+L+a[i]+add[1]*i+add[2]*(i-1)+L+add[i]*1
	  = \sum_{x=1}^i a[x] + \sum_{x=1}^i {add[x]*(i+1-x)}
	  = \sum_{x=1}^i a[x] + (i+1)* (\sum_{x=1}^i {add[x]}) - (\sum_{x=1}^i {add[x]*x})
\sum_{x=1}^i a[x]->ini,make 2 BIT to maintain add[x] & add[x]*x
*/ 
#include<iostream>
#include<cstdio>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll sum[maxn]={0},add[maxn]={0},addS[maxn]={0},n,q;
void update(ll*,int,int);
ll query(ll*,ll);
ll getsum(int,int);
void UP(int,int,int);
int main()
{
	int x;
	char op[5];
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	while(q--)
	{
		int a,b,c;
		scanf("%s",op);
		if(op[0]=='Q') scanf("%d%d",&a,&b),printf("%lld\n",getsum(a,b));
		else scanf("%d%d%d",&a,&b,&c),UP(a,b,c);
	}
	return 0;
}
void update(ll *a,int p,int val)
{
	for(int i=p;i<=n;i+=lowbit(i))//lowbit!! No i++
	{
		a[i]+=val;
	}
}
ll query(ll *a,int p)
{
	ll ret=0;
	for(int i=p;i>0;i-=lowbit(i))//lowbit!! No i--
	{
		ret+=a[i];
	}
	return ret;
}
void UP(int l,int r,int val)
{
	update(add,l,val);
	update(add,r+1,-val);
	update(addS,l,val*l);
	update(addS,r+1,-val*(r+1));
}
ll getsum(int l,int r)
{
	return (sum[r]-sum[l-1])+((r+1)*query(add,r)-l*query(add,l-1))-(query(addS,r)-query(addS,l-1));
}
