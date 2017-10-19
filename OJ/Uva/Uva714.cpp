#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=502;
bool flag[maxn]={0};
int a[maxn]={0};
ll avr=0,r,l;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			avr+=a[i];
		}
		l=0,r=avr;
		avr/=m;
		ll mid=avr;
		while(l<r)
		{
			cls(flag);
			int tmp=0;
			for(int i=n,j=m-1;i>0;i--)
			{
				if(j!=0)
				{
					if((tmp+a[i])>mid)
					{
						flag[i]=1;
						tmp=a[i];
						j--;
					}
					else
					{
						tmp+=a[i];
					}
				}
				else
				{
					tmp+=a[i];
				}
			}
			if(tmp>mid) l=mid+1,mid=l+((r-l)>>1);
			else r=mid,mid=l+((r-l)>>1);
		}
		for(int i=1;i<=n-1;i++)
		{
			printf("%d ",a[i]);
			if(flag[i]) printf("/ ");
		}
		printf("%d\n",a[n]);
		cls(a),cls(flag);
	}
	return 0;
}