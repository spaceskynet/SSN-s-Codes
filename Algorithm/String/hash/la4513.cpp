#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=4e4+10,sed=31;
typedef unsigned long long ull;
int n,m,pos;
char s[maxn];
ull Hash[maxn],hasub[maxn],seed[maxn];
int r[maxn];
bool cmp(const int &a,const int &b);
bool check(int len);
int main()
{
	scanf("%d",&m);
	while(m!=0)
	{
		scanf("%s",s);
		n=strlen(s);
		hasub[n]=0;
		for(int i=n-1;i>=0;i--)
		{
			hasub[i]=hasub[i+1]*sed+(s[i]-'a');
		}
		seed[0]=1;
		for(int i=1;i<=n;i++)
		{
			seed[i]=seed[i-1]*sed;
		}
		if(!check(1)) printf("none\n");
		else
		{
			int l=1,r=n+1;
			while(r-l>1)
			{
				int mid=(l+r)>>1;
				if(check(mid)) l=mid;
				else r=mid;
			}
			check(l);
			printf("%d %d\n",l,pos);
		}
		scanf("%d",&m);
	}
	return 0;
}
bool cmp(const int &a,const int &b)
{
	return Hash[a]<Hash[b]||(Hash[a]==Hash[b]&&a<b);
}
bool check(int len)
{
	int cnt=0;pos=-1;
	for(int i=0;i<n-len+1;i++)
	{
		r[i]=i;
		Hash[i]=hasub[i]-hasub[i+len]*seed[len];
	}
	sort(r,r+n-len+1,cmp);
	for(int i=0;i<n-len+1;i++)
	{
		if(i==0||Hash[r[i]]!=Hash[r[i-1]]) cnt=0;
		if(++cnt>=m) pos=max(pos,r[i]);
	}
	return pos>=0;
}
