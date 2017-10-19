#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int md=1e9+7,maxn=4;
typedef long long ll;
struct Matrix
{
	ll a[maxn][maxn];
	int r,c;
}ori,res;
int mod[5]={md,2000000016,329616,432,72},n,p;
Matrix multi(Matrix a,Matrix b,ll MOD);
int power(int,ll);
void ini();
int main()
{
	scanf("%d%d",&n,&p);
	if(p!=md)
	{
		for(int i=1;i<=4;i++) mod[i]=0;
		mod[0]=p;
		int x=0,y=1,z;
		for(int i=1;i<=4;i++)
		{
			while(1)
			{
				z=x+y;
				if(z>=mod[i-1]) z-=mod[i-1];
				x=y,y=z;
				mod[i]++;
				if(x==0&&y==1) break;
			}
		}
	}
//	for(int i=0;i<=4;i++) printf("%d\n",mod[i]);
	int ans=n;
//	printf("%d\n",p);
	for(int i=3;i>=1;i--)
	{
		ini();
		int x=power(ans%mod[i],mod[i-1]);
		ans=x;
	}
	ans%=p;
	printf("%d",ans);
	return 0;
}
//æÿ’ÛøÏÀŸ√›«ÛFbi
Matrix multi(Matrix x, Matrix y,ll MOD)
{
	Matrix z;
	memset(z.a,0,sizeof(z.a));
	z.r=x.r,z.c=y.c;
	for(int i=1;i<=x.r;i++)
	{
		for(int k=1;k<=x.c;k++)
		{
			if(x.a[i][k]==0) continue;
			for(int j=1;j<=y.c;j++)
				z.a[i][j]=(z.a[i][j]+(x.a[i][k]*y.a[k][j])%MOD)%MOD;
		}
	}
	return z;
}
int power(int n,ll MOD)
{
	while(n)
	{
		if(n&1)
			res=multi(ori,res,MOD);
		ori=multi(ori,ori,MOD);
		n>>=1;
	}
	return res.a[1][2]%MOD;
}
void ini()
{
	memset(res.a,0,sizeof(res.a));
	res.r=2;
	res.c=2;
	for(int i=1;i<=2;i++)
		res.a[i][i]=1;
	ori.r=2;
	ori.c=2;
	ori.a[1][1]=ori.a[1][2]=ori.a[2][1]=1;
	ori.a[2][2]=0;
}
