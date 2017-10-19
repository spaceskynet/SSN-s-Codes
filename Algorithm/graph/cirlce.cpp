#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=200010;
int n,s[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		int res=0,maxx=0;
		for(int i=1;i<=n;i++)
		{
			res+=s[i];
			if(res>maxx)
				maxx=res;
			if(res<0)
				res=0;
		}
		for(int i=1;i<=n;i++)
			s[i]=-1*s[i];
		int res2=0,maxx2=0;
		for(int i=1;i<=n;i++)
		{
			res2+=s[i];
			if (res2>maxx2)
				maxx2=res2;
			if (res2<0)
				res2=0;
		}
		printf("%d\n",max(maxx,sum+maxx2));
	}
	return 0;
}
