//%std
#include<iostream>
#include<cstdio>
#include<set>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=2*1e5+10;
struct sets
{
	int a,g;
	sets(int a,int g):a(a),g(g) {}
	bool operator < (const sets &tp) const
	{
		return a<tp.a;
	}
};
set<sets> ac;
int a[maxn],f[maxn],g[maxn];
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		g[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i-1]<a[i]) g[i]=g[i-1]+1;
			else g[i]=1;
		}
		f[n]=1;
		for(int i=n-1;i>0;i--)
		{
			if(a[i]<a[i+1]) f[i]=f[i+1]+1;
			else f[i]=1;
		}
		ac.clear();
		ac.insert(sets(a[1],g[1]));
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			sets c(a[i],g[i]);
			set<sets>::iterator it = ac.lower_bound(c);
			bool flag=1;
			if(it!=ac.begin())
			{
				sets last=*(--it);
				int len=f[i]+last.g;
				ans=max(len,ans);
				if(c.g<=last.g) flag=0;
			}
			if(flag)
			{
				ac.insert(c);
				it=ac.find(c);
				it++;
				while(it!=ac.end()&&it->a>c.a&&it->g<=c.g)
				{
					ac.erase(it++);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}