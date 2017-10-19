#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e2+10,mod=1e9+7;
typedef long long ll;
struct Matrix
{
	ll a[maxn][maxn];
	int r,c;
}a;
int n;
ll k;
Matrix multi(Matrix,Matrix);
Matrix power(Matrix,ll);
Matrix operator * (const Matrix &a,const Matrix &b){return multi(a,b);}
Matrix operator ^ (const Matrix &a,const ll &b){return power(a,b);}
int main()
{
	scanf("%d%lld",&n,&k);
	a.r=a.c=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a.a[i][j]);
		}
	}
	a=a^k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			printf("%lld ",a.a[i][j]);
		}
		printf("%lld\n",a.a[i][n]);
	}
	return 0;
}
Matrix multi(Matrix x,Matrix y)
{
	Matrix z;
	memset(z.a,0,sizeof(z.a));
	z.r=x.r;z.c=y.c;
	for(int i=1;i<=x.r;i++)
	{
		for(int k=1;k<=x.c;k++)
		{
			if(x.a[i][k]==0) continue;
			for(int j=1;j<=y.c;j++)
			{
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod);
				if(z.a[i][j]>mod) z.a[i][j]%=mod;
			}
 		}
	}
	return z;
}
Matrix power(Matrix I,ll times)
{
	Matrix pre;
	memset(pre.a,0,sizeof(pre.a));
	pre.r=pre.c=n;
	for(int i=1;i<=n;i++) pre.a[i][i]=1;
	while(times)
	{
		if(times&1) pre=pre*I;
		I=I*I;
		times>>=1;
	}
	return pre;
}
