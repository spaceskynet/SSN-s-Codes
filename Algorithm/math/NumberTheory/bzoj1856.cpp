#include<iostream>
#include<cstdio>
#define min(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=20100403;
int n,m;
int fac[maxn<<1];
ll fp(ll,ll);
ll C(int,int);
void init();
int main()
{
//	freopen("a.in","r",stdin);
	init();
	scanf("%d%d",&n,&m);
	printf("%lld\n",(C(m+n,n)-C(m+n,m-1)+mod)%mod);
	return 0;
}
ll fp(ll a,ll b)
{
	ll ret=1,p=b+2;
	a%=p;
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
	return fac[n]*fp(fac[m],mod-2)%mod*fp(fac[n-m],mod-2)%mod;
}
void init()//先预处理，不然要超时
{
    fac[0]=1;
    for(int i=1;i<=(maxn<<1);i++)
    {
        fac[i]=fac[i-1]*(ll)i%mod; 
	}
}
