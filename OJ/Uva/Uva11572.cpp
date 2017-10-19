//%std
#include<iostream>
#include<cstdio>
#include<set>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		set<int> ac;
		int l=1,r=1,ans=0;
		while(r<=n)
		{
			while(r<=n&&!ac.count(a[r]))
			{
				ac.insert(a[r++]);
			}
			ans=max(ans,r-l);
			ac.erase(a[l++]);
		}
		printf("%d\n",ans);
	}
	return 0;
}