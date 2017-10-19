#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define lowbit(x) ((x)&(-(x)))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=6e5+10;
typedef long long ll;
ll sum[maxn];
int a[maxn],b[maxn],f[maxn],fu[maxn],n,ma=0;
void update(int,int);
ll query(int);
ll getsum(int,int);
int bs(int,int,int);
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a+1,a+n+1);
//		int size=unique(a+1,a+n+1)-a-1;
//		for(int i=1;i<=n;i++)
//		{
//			b[i]=upper_bound(a+1,a+n+1,b[i])-a-1;
//			size=max(b[i],size);
//		}
		int cnt=0;
		fu[++cnt]=a[1];
		for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) fu[++cnt]=a[i];
		ma=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=bs(b[i],1,cnt);
			ma=max(ma,f[i]);
		}
		ll ans=0;
		cls(sum,0);
		for(int i=1;i<=n;i++)
		{
			ans+=getsum(f[i]+1,ma);
			update(f[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
void update(int p,int val)
{
	for(int i=p;i<=ma;i+=lowbit(i))
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
ll getsum(int l,int r)
{
	return query(r)-query(l-1);
}
int bs(int val,int l,int r)
{
	int m;
	while(l<r)
	{
		m=(l+r)>>1;
		if(fu[m]>=val) r=m;// >= !! 
		else l=m+1;
	}
	return l;
}
