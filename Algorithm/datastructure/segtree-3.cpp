//hdu 1394
#include<iostream>
#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define min(a,b) ((a)<(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=2e5+10;
int sum[maxn<<2]={0},a[maxn]={0},n;
void update(int,int,int,int,int);
int query(int,int,int,int,int);
void PushUP(int);
int main()
{
	while(~scanf("%d",&n))
	{
		cls(sum,0);
		int s=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&i[a]);
			i[a]++;//因为数中有0，都加上1。 
			s+=query(a[i]+1,n,1,n,1);
			update(a[i],1,1,n,1);
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
void update(int p,int val,int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]+=val;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) update(p,val,lson);
	else update(p,val,rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return sum[rt];
	int m=(l+r)>>1,ret=0;
	if(L<=m) ret+=query(L,R,lson);
	if(R>m) ret+=query(L,R,rson);
	return ret;
}
void PushUP(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
