#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=1e5+10,INF=(1<<30);
typedef long long ll;
ll a[maxn]={0},f[maxn],n,mz=-INF,mf=-INF;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	f[1]=0;
	f[2]=max(a[1],a[2])-min(a[1],a[2]);
	mz=max(-a[1],-a[2]);
	mf=max(a[1],a[2]);
	for(int i=3;i<=n;i++)
	{
		f[i]=max(a[i]+mz,mf-a[i]);
		f[i]=max(f[i-1],f[i]);
		mz=max(f[i-1]-a[i],mz);
		mf=max(f[i-1]+a[i],mf);
	}
	printf("%lld",f[n]);
	return 0;
}
