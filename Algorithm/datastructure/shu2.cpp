#include<iostream>
#define MAXN 500000+10
using namespace std;
int C[MAXN]={0},A[MAXN]={0};
int lowbit(int x); 
int query(int x);
void updata(int n,int pos,int val);
int sum(int l,int r);
int main()
{
	int n,m,x,y,z;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		updata(n,i,A[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1) updata(n,x,y);
		else cout<<sum(x,y)<<endl;
	}
	return 0;
}
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		s+=C[i];
	}
	return s;
}
void updata(int n,int pos,int val)
{
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		C[i]+=val;
	}
}
int sum(int l,int r)
{
	return query(r)-query(l-1);
}

