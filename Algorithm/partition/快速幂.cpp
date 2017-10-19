#include<cstdio>
typedef long long ll;
ll quicksqrt(ll,ll,ll);
int main()
{
	ll a,b,k;
	scanf("%ld%ld%ld",&a,&b,&k);
	printf("%ld",quicksqrt(a,b,k));
	return 0;
}
ll quicksqrt(ll a,ll b,ll k)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=(ans*a)%k;
		}
		a=(a*a)%k;
		b>>=1;
	}
	return ans;
}
