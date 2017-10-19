//spaceskynet 2017-09-01 Leftist-Tree (Biggest-First)
#include<iostream>
#include<cstdio>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
struct node
{
	int ls,rs,val,dis;
	node(){}
	node(int ls,int rs,int val,int dis):
		ls(ls),rs(rs),val(val),dis(dis){}
}Ltree[maxn];
vector<int> s[maxn];
ll ans=0;
int n,m,B[maxn],C[maxn],L[maxn],root[maxn],sum[maxn],num[maxn];
int pop(int);
int merge(int,int);
int Find(int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&B[i],&C[i],&L[i]);
		s[B[i]].push_back(i);
		root[i]=i;
	}
	for(int i=n;i>0;i--)
	{
		if(C[i]<=m)
		{
			Ltree[i]=node(0,0,C[i],0);
			sum[i]=C[i],num[i]=1;
		}
		else Ltree[i]=node(0,0,0,0);
		for(int j=(int)s[i].size()-1;~j;j--)
		{
			root[i]=merge(root[i],root[s[i][j]]);
			sum[i]+=sum[s[i][j]];
			num[i]+=num[s[i][j]];
			while(sum[i]>m) root[i]=pop(i);
		}
		ans=max(ans,1ll*L[i]*num[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
int pop(int x) 
{
	int ls=Ltree[root[x]].ls,rs=Ltree[root[x]].rs;
	sum[x]-=Ltree[root[x]].val;
	--num[x];
//	Ltree[ls].fa=ls,Ltree[rs].fa=rs;
	Ltree[root[x]]=node(0,0,C[root[x]],0);
//	sum[root[x]]=C[root[x]],num[root[x]]=1;
	return merge(ls,rs);
}
int merge(int l,int r)
{
	if(l==0) return r;
	if(r==0) return l;
	if(Ltree[l].val<Ltree[r].val) swap(l,r);
	Ltree[l].rs=merge(Ltree[l].rs,r);
//	Ltree[Ltree[l].rs].fa=l;
	if(Ltree[Ltree[l].ls].dis<Ltree[Ltree[l].rs].dis) swap(Ltree[l].ls,Ltree[l].rs);
	if(Ltree[l].rs==0) Ltree[l].dis=0;
	else Ltree[l].dis=Ltree[Ltree[l].rs].dis+1;
	return l;
}
//int Find(int x)
//{
//	return Ltree[x].fa==x?x:Find(Ltree[x].fa);
//}
