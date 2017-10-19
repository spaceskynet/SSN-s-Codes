//spaceskynet 2017-09-02 BIT
#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-(x))) 
using namespace std;
const int maxn=6e3+10;
int sum[maxn]={0},a[maxn]={0},n;
void update(int,int);
int query(int);
int getsum(int,int);
int main()
{
	while(~scanf("%d",&n))
	{
		cls(sum,0);
		int s=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			a[i]++;//因为数中有0，都加上1。 
			s+=getsum(a[i]+1,n);
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
	for(int i=p;i<=n;i+=lowbit(i))
	{
		sum[i]+=val;
	}
}
int query(int p)
{
	int ret=0;
	for(int i=p;i>0;i-=lowbit(i))
	{
		ret+=sum[i];
	}
	return ret;
}
int getsum(int l,int r)
{
	return query(r)-query(l-1);
}
