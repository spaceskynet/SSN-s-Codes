#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class
struct qujian
{
	int l,r;
}part[100010];
//Definition Global variables
//Definition Function
int cmp(qujian a,qujian b);
int read();
//Main Function
int main()
{
	int n,m,l,r,tree=1,rmax;
	n=read();
	m=read();
	for(int i=0;i<m;i++)
	{
		part[i].l=read(),part[i].r=read();
	}
	sort(part+0,part+m,cmp);
	tree+=part[0].l-1;
	rmax=part[0].r;
	for(int i=1;i<m;i++)
	{
		if(part[i].l>=part[i-1].r)
		{
			tree++;
			if(part[i].l>rmax) tree+=(part[i].l-rmax-1);
		}
		if(part[i].r>rmax) rmax=part[i].r;
	}
	tree+=(n-rmax);
	cout<<tree<<endl;
	return 0;
}
//DIY Function
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		n=n*10+c-'0';
		c=getchar();
	}
	return n*f;
}
int cmp(struct qujian a,struct qujian b)
{
	return a.l<b.l;
}
