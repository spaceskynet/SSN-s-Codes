//spaceskynet 2017-07-21 BIT
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int n,m;
ll a[maxn],c1[maxn],c2[maxn];
void updata(ll *b,int,ll);
ll query(ll *b,int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		updata(c1,i,a[i]);
		updata(c2,i,a[i]*a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			updata(c1,l,r-a[l]),updata(c2,l,r*r-a[l]*a[l]);
			a[l]=r;
		}
		else
		{
			ll x=(query(c1,r)-query(c1,l-1));
			ll ans=(r-l+1)*(query(c2,r)-query(c2,l-1))-x*x;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
void updata(ll *b,int x,ll y)
{
	for(;x<=n;x+=lowbit(x))
	{
		b[x]+=y;
	}
}
ll query(ll *b,int x)
{
	ll ans=0;
	for(;x;x-=lowbit(x))
	{
		ans+=b[x];
	}
	return ans;
}
