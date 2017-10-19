//%std
#include<cstdio>
#define abs(a) ((a)>0?(a):(-(a)))
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		long long ans=0,a,cur=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			ans+=abs(cur);
			cur+=a;
		}
		printf("%lld\n",ans);
	}
	return 0;
}