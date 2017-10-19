#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int num[101]={0};
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+0,num+n);
	for(int i=0;i<n;i++)
	{
		int x=1,d;
		for(int j=i+1;j<n;j++)
		{
			if(j==i+1) d=num[j]-num[i];
			if((num[j]-num[i])==d*x) x++;
		}
		ans=ans>x?ans:x;
	}
	printf("%d",ans);
	return 0;
}