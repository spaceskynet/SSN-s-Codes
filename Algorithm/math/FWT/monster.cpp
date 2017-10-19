#include<iostream>
#include<cstdio>
#define md(a,b) ((a)+(b)-(((a)+(b)>=mod)?(mod):0))
using namespace std;
typedef long long ll;
const int mod=593119681,rev=(mod+1)>>1,maxn=(1<<18)+10;
int a[maxn],b[maxn],n,t;
void FWT(int *p);
void UFWT(int *p);
int power(int,int);
int main()
{
	scanf("%d%d",&n,&t);
    for(int i=0;i<(1<<n);i++)
		scanf("%d",&a[i]);
	b[0]=1;
    for(int i=0;i<n;i++)
		b[1<<i]=1;
    FWT(a),FWT(b);
    for(int i=0;i<(1<<n);i++)
        b[i]=(ll)power(b[i],t)*a[i]%mod;
    UFWT(b);
    for(int i=0;i<(1<<n);i++)
        printf("%d%c",b[i],i==(1<<n)-1?'\n':' ');
	return 0;
}
void FWT(int *p)
{
	for(int k=1;k<(1<<n);k<<=1)
	{
		for(int i=0;i<(1<<n);i++)
		{
			if(i&k) continue;
			int x=md(p[i],p[i+k]),
				y=md(p[i],mod-p[i+k]);
			p[i]=x,p[i+k]=y;
		}
	}
}
void UFWT(int *p)
{
	for(int k=(1<<n-1);k;k>>=1)
	{
		for(int i=0;i<(1<<n);i++)
		{
			if(i&k) continue;
			int x=(ll)md(p[i],p[i+k])*rev%mod,
				y=(ll)md(p[i],mod-p[i+k])*rev%mod;
			p[i]=x,p[i+k]=y;
		}
	}
}
int power(int u,int v)
{
	int ans=1;
	for(;v;v>>=1)
	{
		if(v&1) ans=(ll)ans*u%mod;
		u=(ll)u*u%mod;
	}
	return ans;
}
