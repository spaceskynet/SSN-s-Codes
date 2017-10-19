#include<cstdio>
#include<iostream>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=5e4+10;
int a[maxn]={0},n,m;
void updata(int,int);
int query(int);
int Xor(int,int);
int main()
{
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		updata(i,x);
	}
	int op,l,r;
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op) updata(l,r);
		else printf("%d\n",Xor(l,r));
	}
	return 0;
}
void updata(int pos,int val)
{
	int past=Xor(pos,pos);
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		a[i]^=past;
		a[i]^=val;
	}
}
int query(int x)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		s^=a[i];
	}
}
int Xor(int l,int r)
{
	return query(r)^query(l-1);
}
