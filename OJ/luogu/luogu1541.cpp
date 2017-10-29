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
#define Max(a,b,c,d) max(max(a,b),max(c,d))
using namespace std;
typedef long long ll;
const int maxn=45,maxm=355;
int n,m,f[maxn][maxn][maxn][maxn],cnt[5],w[maxm];
template<typename T>void read(T&);
int main()
{
//	fr();
	read(n),read(m);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x;i<=m;i++) read(x),cnt[x]++;
	for(int i=1;i<=4;i++) cnt[i]++;
	for(int i=1;i<=cnt[1];i++) for(int j=1;j<=cnt[2];j++) for(int k=1;k<=cnt[3];k++) for(int l=1;l<=cnt[4];l++)
	{
		int I=i-1,J=j-1,K=k-1,L=l-1;
		if(I+J*2+K*3+L*4>n) continue;
		f[i][j][k][l]=Max(f[i-1][j][k][l],f[i][j-1][k][l],f[i][j][k-1][l],f[i][j][k][l-1])+w[1+I+J*2+K*3+L*4];
	}
	printf("%d\n",f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
template<typename T>void read(T &x)
{
	x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	x*=f;
}
