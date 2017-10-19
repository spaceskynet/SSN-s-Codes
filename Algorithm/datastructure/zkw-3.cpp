//spaceskynet 2017-09-02 zkw hdu 1394
#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=2e4+10;
int sum[maxn<<1],a[maxn],n,M=1;
void update(int,int);
int query(int,int);
int main()
{
	while(~scanf("%d",&n))
	{
		cls(sum,0);
		int s=0;
		for(M=1;M<=n+1;M<<=1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]++;
			s+=query(a[i]+1,n);
			update(a[i],1);
		}
		int mi=s;
		for(int i=1;i<n;i++)
		{
			mi-=a[i]-1+a[i]-n;
			s=min(s,mi);
		}
		printf("%d\n",s);
	}
	return 0;
}
void update(int p,int val)
{
	sum[p+=M]+=val;
	while(p)
	{
		p>>=1;
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
}
int query(int l,int r)
{
	int ret=0;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ret+=sum[l^1];
		if(r&1) ret+=sum[r^1];
	}
	return ret;
}
