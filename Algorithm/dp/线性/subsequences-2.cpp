#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
typedef long long ll;
ll a[maxn],n,k,h[maxn][15];
void updata(int,ll,int);
ll query(int,int);
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		ll cnt;
		for(int j=k;j>=1;--j)
		{
			cnt=query(a[i],j);
			updata(a[i],cnt,j+1);
		}
		updata(a[i],1,1);
	}
	printf("%lld",query(n,k+1));//O(nk)
	return 0;
}
void updata(int x,ll a,int k)
{
	for(;x<=n;x+=lowbit(x)) 
	{
		h[x][k]+=a;
	}
}
ll query(int x,int k)
{
	ll ans=0;
	for(;x;x-=lowbit(x)) 
	{
		ans+=h[x][k];
	}
	return ans;
}
