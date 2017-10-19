//hdu 5677
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
char s[maxn],str[maxn];
int n,k,l,rad[maxn],cnt[555000]={0},tot=0;
void manacher(char*,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d%d",&n,&k,&l);
		for(int i=1;i<=n;i++)
		{
			memset(rad,0,sizeof(rad));
			scanf("%s",s);
			int x=strlen(s);
			int len=0;
			str[len]='@';
			str[++len]='#';
			for(int i=0;i<x;i++)
			{
				str[++len]=s[i];
				str[++len]='#';
			}
			str[++len]='$';
			manacher(str,len);
		}
		sort(cnt,cnt+tot);
		int sum=0;
		for(int i=0;i<k;i++) sum+=cnt[i];
		if(sum>l) printf("False\n");
		else
		{
			sum=0;
			for(int i=k-1;i>=tot-k;i--) sum+=cnt[i];
			if(sum<l) printf("False\n");
			else printf("True\n");
		}
	}
	return 0;
}
void manacher(char *s,int l)
{
	for(int i=1,j=0,k;i<l;)
	{
		for(;s[i-j-1]==s[i+j+1];j++);
		rad[i]=j;
		for(k=1;k<=j&&rad[i-k]!=rad[i]-k;k++)
		{
			rad[i+k]=min(rad[i-k],rad[i]-k);
		}
		i+=k;
		j=max(j-k,0);
	}
	for(int i=2;i<l-1;i++) 
	{
		while(rad[i]>0) cnt[tot++]=rad[i],rad[i]-=2;
	}
}
