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
const int maxn=5e3+10;
db f[2][maxn];
int R,B;
int read();
int main()
{
//	fr();
	R=read(),B=read();
	bool d=0;
	for(int i=1;i<=R;i++)
	{
		f[d][0]=i;
		for(int j=1;j<=B;j++)
		{
			f[d][j]=max(0.0,i*1.0/(i+j)*(f[d^1][j]+1)+j*1.0/(i+j)*((f[d][j-1])-1));
		}
		d^=1;
	}
	printf("%.6f\n",f[d^1][B]-5e-7);	
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