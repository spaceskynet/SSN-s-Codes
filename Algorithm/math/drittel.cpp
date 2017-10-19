#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll maxn=5e3+10,mod=1234567891;
ll n,k,f[maxn][maxn]={0};
ll fpwr(ll,ll);
int main()
{
	scanf("%lld%lld",&n,&k);
	f[0][0]=1;
	for(int i=1;i<=k+1;i++)
	{
		f[0][i]=(f[0][i-1]+fpwr(3*i+1,k))%mod;
	}
	for(int i=1;i<=k+1;i++)
	{
		for(int j=i;j<=k+1;j++)
		{
			f[i][j]=(f[i-1][j]-f[i-1][j-1]+mod)%mod;
		}
	}
	ll ans=0,ret=1;
	for(int i=0;i<=k+1;i++)
	{
		ans=(ans+f[i][i]*ret)%mod;
		ret=ret*(n-i-1)%mod*fpwr(i+1,mod-2)%mod;
	}
	printf("%lld",ans);
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
