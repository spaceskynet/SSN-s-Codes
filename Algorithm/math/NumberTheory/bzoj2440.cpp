//spaceskynet 2017-08-19 mobiwusi func+half-find
#include<iostream>
#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int x,t;
int mu[maxn]={0},prime[maxn],ptot=0;
bool bo[maxn]={0};
void getmu(int);
ll solve(int);
int main()
{
	scanf("%d",&t);
	getmu(maxn);
	while(t--)
	{
		scanf("%d",&x);
		printf("%lld\n",solve(x));
	}
	return 0;
}
void getmu(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!bo[i]) prime[++ptot]=i,mu[i]=-1;
		for(int j=1;j<=ptot&&i*prime[j]<=n;j++)
		{
			bo[i*prime[j]]=1;
			if(i%prime[j]) mu[i*prime[j]]=-mu[i];
			else {mu[i*prime[j]]=0;break;}
		}
	}
}
ll check(ll mid)
{
	ll tot=0;
	for(ll i=1;i*i<=mid;i++)
	{
		tot+=mu[i]*mid/(i*i);
	}
	return tot;
}
ll solve(int k)
{
	ll l=1,r=(k<<1);
	ll mid=(l+r)>>1;
	while(l<r)
	{
		ll tot=check(mid);
		if(tot<k) l=mid+1;
		else r=mid;
		mid=(l+r)>>1;
	}
	return mid;
}
