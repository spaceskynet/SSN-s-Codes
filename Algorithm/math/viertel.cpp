#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=10007,maxk=1e3+10;
struct Matrix
{
	int a[maxk][maxk];
	int r,c;
}ori,res;
int m=0,g=0,ans=0;
int fir[maxk<<1]={0};
Matrix multi(Matrix a,Matrix b);
//int Power(int);
void ini();
int main()
{
	scanf("%d%d",&m,&g);
	for(int i=0;i<g;i++) fir[i]=1;
	for(int i=g;i<(g<<1);i++)
	{
		for(int j=i-1;j>=i-g;j--)
		{
			fir[i]+=fir[j];
		}
	}
	ini();
	ans=m-2*g+1;
	while(ans)
	{
		if(ans&1) res=multi(ori,res);
		ori=multi(ori,ori);
		ans>>=1;
	}
	ans=res.a[0][g-1]%MOD;
	printf("%d",ans);
	return 0;
}
Matrix multi(Matrix x, Matrix y)
{
	Matrix z;
	memset(z.a,0,sizeof(z.a));
	z.r=x.r,z.c=y.c;
	for(int i=0;i<x.r;i++)
	{
		for(int k=0;k<x.c;k++)
		{
			if(x.a[i][k]==0) continue;
			for(int j=0;j<y.c;j++)
				z.a[i][j]=(z.a[i][j]+(x.a[i][k]*y.a[k][j])%MOD)%MOD;
		}
	}
	return z;
}
//int Power(int b)
//{
////	printf("%d",&n);
//	while(b)
//	{
//		if(b&1) res=multi(ori,res);
//		ori=multi(ori,ori);
//		b>>=1;
//	}
//	return res.a[0][g-1]%MOD;
//}
void ini()
{
	memset(res.a,0,sizeof(res.a));
	res.r=1;
	res.c=g;
	for(int i=0;i<g;i++)
		res.a[0][i]=fir[g+i];
	ori.r=g;
	ori.c=g;
	for(int i=0;i<g;i++)
	{
		for(int j=0;j<g;j++)
		{
			if(i<=j) ori.a[i][j]=1;
			else ori.a[i][j]=0;
		}
	}
}
