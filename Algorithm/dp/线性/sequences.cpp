#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define max3(a,b,c) ((max(a,b))>(c)?(max(a,b)):(c))
using namespace std;
const int maxn=1e4+10;
int f[maxn][maxn],n;
char a[maxn];
bool check(int,int);
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(check(i,j+i)) f[j][j+i]=max3(f[j+1][j+i-1],f[j+1][j+i]+1,f[j][j+i-1]+1);
			else f[j][j+i]=max(f[j+1][j+i]+1,f[j][j+i-1]+1);
		}
	}
	printf("%d",f[1][n]);
	return 0;
}
bool check(int x,int y)
{
	return (a[x]=='['&&a[y]==']')||(a[x]=='('&&a[y]==')');
}
