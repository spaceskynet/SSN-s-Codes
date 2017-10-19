#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int sum[maxn],a[maxn];
int cp(int,int,int,int);
int main()
{
	int n,l,t=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&l,s+1);
		sum[0]=1;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+s[i]-'0';
		}
		int ansl=1,ansr=l;
		int i=0,j=0;
		for(int x=l;x<=n;x++)
		{
			while(j-i>1&&cp(a[j-2],x-l,a[j-1],x-l)>=0)
			{
				j--;
			}
			a[j++]=x-l+1;
			while(j-i>1&&cp(a[i],x,a[i+1],x)<=0)
			{
				i++;
			}
			int c=cp(a[i],x,ansl,ansr);
			if(c>0||c==0&&x-a[i]<ansr-ansl)
			{
				ansl=a[i],ansr=x;
			}
			
		}
		printf("%d %d\n",ansl,ansr);
	}
	return 0;
}
int cp(int x1, int x2, int x3, int x4)
{
	return (sum[x2]-sum[x1-1])*(x4-x3+1)-(sum[x4]-sum[x3-1])*(x2-x1+1);
}