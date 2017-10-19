#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int mod=1e8;
struct Matrix
{
	int a[2][2];
	int r,c;
}ret,I;
int n,m;
int read();
int fp(int);
int gcd(int,int);
Matrix mul(Matrix,Matrix);
void init();
int main()
{
//	fr();
	n=read(),m=read();
	int d=gcd(n,m);
	init();
	printf("%d\n",fp(d));
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void init()
{
	I.a[0][0]=I.a[0][1]=I.a[1][0]=1,I.a[1][1]=0,I.r=I.c=ret.r=ret.c=2;
	ret.a[0][0]=ret.a[1][1]=1,ret.a[0][1]=ret.a[1][0]=0;
}
Matrix mul(Matrix x,Matrix y)
{
	Matrix z;
	mem(z.a,0);
	z.r=x.r,z.c=y.c;
	for(int i=0;i<x.r;i++)
	{
		for(int k=0;k<x.c;k++)
		{
			if(!x.a[i][k]) continue;
			for(int j=0;j<y.c;j++)
			{
				z.a[i][j]=(1ll*z.a[i][j]+1ll*x.a[i][k]*y.a[k][j])%mod;
			}
		}
	}
	return z;
}
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int fp(int times)
{
	while(times)
	{
		if(times&1) ret=mul(ret,I);
		times>>=1,I=mul(I,I);
	}
	return ret.a[0][1]%mod;
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}