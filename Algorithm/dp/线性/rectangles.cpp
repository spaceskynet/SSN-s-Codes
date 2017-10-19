//20%
#include<iostream>
#include<cstdio>
using namespace std;
int m,n,q,f[42][42],a,b,c,d;
char str[50];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%s",str);
	for(int i=1;i<=n;i++) f[i][1]=((i+1)*i)>>1;
	for(int i=2;i<=m;i++) f[1][i]=((i+1)*i)>>1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			f[i][j]=f[i][1]*f[1][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",f[c-a+1][d-b+1]);
	}
	return 0;
}
