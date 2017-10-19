#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k;
ll f[maxn],l[maxn];
ll fpwr(ll,ll);
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=2;i<=k+2;i++)
	{
		f[i]=(f[i-1]+fpwr(3*i-2,k))%mod;
	}
	if(n<=k+2)
	{
		printf("%lld",f[n]);
		return 0;
	}
	
	return 0;
}
ll fpwr(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
	}
	return ans;
}
