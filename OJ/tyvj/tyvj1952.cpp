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
typedef double db;
const int maxn=5e5+10;
int n;
char s[maxn];
db f[maxn],g[maxn];
int read();
int main()
{
//	fr();
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='x') f[i]=f[i-1],g[i]=0;
		else if(s[i]=='o') f[i]=f[i-1]+g[i-1]*2+1,g[i]=g[i-1]+1;
		else f[i]=f[i-1]+g[i-1]+0.5,g[i]=(g[i-1]+1)/2;
	}
	printf("%.4f\n",f[n]);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}