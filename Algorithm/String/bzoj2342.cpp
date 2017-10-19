#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int n;
char s[maxn],str[maxn];
void manacher(char*,int);
int main()
{
	scanf("%d%s",n,s);
	int len=0;
	str[len]='@';
	str[++len]='#';
	for(int i=0;i<n;i++)
	{
		str[++len]=s[i];
		str[++len]='#';
	}
	str[++len]='$';
	manacher(str,len);
	return 0;
}
void mancher(char *s,int l)
{
	for(int i=1,j=0,k;i<l;)
	{
		for(;s[i-j-1]==s[i+j+1];j++);
		rad[i]=j;
		for(k=1;k<=j&&rad[i]-k!=rad[i-k];k++)
		{
			rad[i+k]=min(rad[i]-k,rad[i-k]);
		}
		i+=k;
		j=max(j-k,0);
	}
}
