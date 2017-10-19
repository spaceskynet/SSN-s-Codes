//spaceskynet 2017-08-08 莫队
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
struct block
{
	int l,r,id;
}k[maxn];
ll gcd(ll,ll);
struct Ans
{
	ll a,b;
	void dv()
	{
		ll d=gcd(a,b);
		a/=d,b/=d;
	}
}ans[maxn];
int n,m,sn,a[maxn],t[maxn];
void solve();
bool cmp(const block &,const block &);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		k[i].id=i;
		scanf("%d%d",&k[i].l,&k[i].r);
	}
	sn=(int)sqrt(n);
	sort(k,k+m,cmp);
	solve();
	for(int i=0;i<m;i++)
	{
		printf("%lld/%lld\n",ans[i].a,ans[i].b);
	}
	return 0;
}
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
bool cmp(const block &a,const block &b)
{
	if(a.l/sn!=b.l/sn) return a.l/sn<b.l/sn;
	else return a.r<b.r;
}
void solve()
{
	ll tp=0;
	cls(t,0);
	int l=1,r=0;
	for(int i=0;i<m;i++)
	{
		while(r<k[i].r)
		{
			r++;tp-=(ll)t[a[r]]*t[a[r]];
			t[a[r]]++;tp+=(ll)t[a[r]]*t[a[r]];
		}
		while(r>k[i].r)
		{
			tp-=(ll)t[a[r]]*t[a[r]];t[a[r]]--;
			tp+=(ll)t[a[r]]*t[a[r]];r--;
		}
		while(l>k[i].l)
		{
			l--;tp-=(ll)t[a[l]]*t[a[l]];
			t[a[l]]++;tp+=(ll)t[a[l]]*t[a[l]];
		}
		while(l<k[i].l)
		{
			tp-=(ll)t[a[l]]*t[a[l]];t[a[l]]--;
			tp+=(ll)t[a[l]]*t[a[l]];l++;
		}
		ans[k[i].id].a=tp-(r-l+1);
		ans[k[i].id].b=(ll)(r-l+1)*(r-l);
		ans[k[i].id].dv();
	}
}