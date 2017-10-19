//C(n,m)%p Lucas spaceskynet 08-21
#include<cstdio>
typedef long long ll;
int n,m,p;
ll fp(ll,ll);
ll C(int,int);
ll Lucas(int,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		printf("%lld\n",Lucas(n,m));
	}
	return 0;
}
ll fp(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
ll C(int n,int m)
{
	if(m>n) return 0;
	ll ret=1;
	for(int i=1;i<=m;i++)//from n to (n-m+1)
	{
		ll a=(n+i-m)%p;
		ll b=i%p;
		ret=ret*(a*fp(b,p-2)%p)%p;
	}
	return ret;
}
ll Lucas(int n,int m)
{
	if(m==0) return 1;
	else return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}
