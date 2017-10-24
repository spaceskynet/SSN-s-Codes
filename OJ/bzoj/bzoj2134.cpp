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
const int maxn=1e7+10,mod=100000001;
int a[maxn]={0},n,A,B,C;
int read();
int main()
{
//	fr();
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&a[1]);
	for(int i=2;i<=n;i++) a[i]=(1ll*a[i-1]*A+B)%mod;
	for(int i=1;i<=n;i++) a[i]=a[i]%C+1;
	a[0]=a[n];
	db ans=0.0;
	for(int i=1;i<=n;i++) ans+=1.0/max(a[i],a[i-1]);
	printf("%.3f\n",ans);
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