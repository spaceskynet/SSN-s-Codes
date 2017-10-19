#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
typedef long long ll;
ll a[maxn],n,k,f[maxn],h[maxn][15],g[maxn],b[maxn],ma=-INF,stack[maxn],top=0,over=1;
ll C(ll);
void updata(int,ll,int);
ll query(int,int);
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[a[i]]=i;
		g[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(b[j]<b[i]&&g[j]+1>g[i])
				g[i]=g[j]+1;
		}
	}
	for(int i=1;i<=n;i++) ma=max(ma,g[i]),g[i]=ma;
	f[k]=0;
	for(int i=2;i<=k+1;i++) over*=i;
	for(int i=k+1;i<=n;i++)	
	{
		f[i]=f[i-1]+C(g[a[i]]);
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
	if(n<=1e3) printf("%lld",query(n,k+1));//O(n^2)
	else printf("%lld",f[n]);//O(nk)?????
	return 0;
}
ll C(ll m)
{
	ll ans=1;
	for(ll i=m;i>=(m-k);i--)
	{
		ans*=i;
	}
	ans/=over;
	return ans;
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
