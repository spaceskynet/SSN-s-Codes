#include<iostream>
#include<cstdio>
#include<cstring>;
using namespace std;
const int maxn=6e3+10,mod=1e9+7;
int x,y,m,n,o,p;
int a[maxn],b[maxn];
char c[20];
int main()
{
	scanf("%d%d",&x,&y);
	scanf("%d%d%d%d",&m,&n,&o,&p);
	while(true)
	{
		fgets(c,20,stdin);
		printf("%s",c);
		if(c[0]<'0'||c[0]>'9') break;
		sscanf(c,"%d%d%d",&n,&o,&p);
		if(n==x) a[o]=p;
		//printf("%d ",a[o]);
	}
	//putchar('\n');
	while(true)
	{
		fgets(c,20,stdin);
		if(c[0]<'0'||c[0]>'9') break;
		sscanf(c,"%d%d%d",&n,&o,&p);
		b[o]+=a[n]*p;
		printf("%d ",b[o]);
	}
	memset(a,0,sizeof(a));
	while(~scanf("%d%d%d",&n,&o,&p))
	{
		a[o]+=b[n]*p;
	}
	printf("%d\n",a[y]);
	return 0;
}

