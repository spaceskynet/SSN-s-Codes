#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100000+10;

char a[maxn],b[maxn];

int cnt[50];

int main()
{
	scanf("%s%s",a,b);
	int la=strlen(a);
	int lb=strlen(b);
	ll ans=1ll*la*lb;
	for(int i=1;i<la;++i) ++cnt[a[i]-'a'];
	for(int i=0;i<lb-1;++i) ans-=cnt[b[i]-'a'];
	cout<<ans;
	return 0;
}

