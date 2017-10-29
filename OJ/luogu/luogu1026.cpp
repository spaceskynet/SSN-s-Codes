#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=2e2+10;
int p,k;
template<typename T>read(T&);
int main()
{
//	fr();
	read(p),read(k);
	for(int i=1;i<=p;i++)
	{
		scanf("%s",str);
	}
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
template<typename T>read(T &x)
{
	x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	x*=f;
}
