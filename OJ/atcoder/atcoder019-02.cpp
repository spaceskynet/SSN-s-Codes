#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll letter[26]={0};
char s[maxn];
int main()
{
	scanf("%s",s);
	ll len=strlen(s);
	ll ans=(len-1)*len/2+1;
	for(int i=0;i<len;i++)
	{
		letter[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		ans-=(letter[i]*(letter[i]-1)/2);
	}
	printf("%lld",ans);
	return 0;
}
