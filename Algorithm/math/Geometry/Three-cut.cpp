#include<cstdio>
typedef double db;
const int maxn=15;
const db eps=1e-6;
int n;
db a[maxn]={0};
db f(db);
int main()
{
	db l,r;
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=0;i<=n;i++)
	{
		scanf("%lf",&a[i]);//看清系数顺序 
	}
	db mid,mmid;
	while(r-l>eps)
	{
		mid=(l+r)/2,mmid=(mid+r)/2;
		if(f(mid)>f(mmid)) r=mmid;
		else l=mid;
	}
	printf("%.5f",mid);
	return 0;
}
db f(db x)
{
	db ret=a[0];
	for(int i=1;i<=n;i++)
	{
		ret=ret*x+a[i];
	}
	return ret;
}

