#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10,mod=1e9+7;
typedef long long ll;
struct Matrix
{
	int a[maxn][maxn];
	int r,c;
};
int n;
Matrix multi(Matrix,Matrix);
Matrix power(Matrix,ll);
Matrix one(Matrix,Matrix,int);
Matrix operator * (const Matrix &a,const Matrix &b){return multi(a,b);}
Matrix operator + (const Matrix &a,const Matrix &b){return one(a,b,1);}
Matrix operator - (const Matrix &a,const Matrix &b){return one(a,b,-1);}
int main()
{
	
	return 0;
}
Matrix multi(Matrix x,Matrix y)
{
	Matrix z;
	z.r=x.r;z.c=y.c;
	for(int i=1;i<=x.r;i++)
	{
		for(int j=1;j<=x.c;j++)
		{
			if(x.a[i][j]==0) continue;
			for(int k=1;k<=y.r;k++)
			{
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
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
		I=multi(I,I);
		times>>=1;
	}
	return pre;
}
Matrix one(Matrix x,Matrix y,int f)
{
	if(x.r==y.r&&x.c==y.c)
	{
		for(int i=1;i<=x.r;i++)
		{
			for(int j=1;j<=x.c;j++)
			{
				x.a[i][j]+=f*y.a[i][j];
			}
		}
		return x;
	}
}

