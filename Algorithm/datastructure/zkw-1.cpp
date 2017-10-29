#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3e5+10;
class zkw
{
public:
	zkw()
	{
		m=1;
	}
	void build(int n)//区间和
	{
		for(;m<n;m<<=1);
		m<<=1;//避免查端点值出错
		for(int i=m+1;i<n+m+1;i++) scanf("%d",&a[i]);//从m+1叶子节点开始，避免查询[0,...]时出错。
		for(int i=m-1;i;--i) a[i]=a[i<<1]+a[i<<1|1];
	}
	int query(int l,int r)
	{
		int ans=0;
		for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)
		{
			if(~l&1) ans+=a[l^1];
			if(r&1) ans+=a[r^1];
		}
		return ans;
	}
	void updata(int pos,int val)
	{
		a[pos+=m]+=val;
		while(pos)
		{
			a[pos>>=1]=a[pos<<1]+a[pos<<1|1];
		}
	}
private:
	int a[2*maxn+2],m;
};
int n,m;
zkw tree;
int main()
{
	scanf("%d",&n);
	tree.build(n);
	int l,r,w;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d%d",&w,&l,&r);
	    if(w==2) printf("%d\n",tree.query(l,r));
	    else tree.updata(l,r);
	}
	return 0;
}