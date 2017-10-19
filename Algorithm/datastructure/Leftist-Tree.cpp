//spaceskynet Leftist-Tree 2017-08-30
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int l,r,fa,val,dis;
	node(){}
	node(int l,int r,int fa,int val,int dis)
		:l(l),r(r),fa(fa),val(val),dis(dis){}
}Ltree[maxn];
int Find(int);
int pop(int);
int merge(int,int);
int main()
{
	int n,m,v,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v);
			Ltree[i]=node(0,0,i,v,0);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			int fx=Find(x),fy=Find(y);
			if(fx==fy) printf("-1\n");
			else
			{
				Ltree[fx].val/=2;
				int l=pop(fx);
				l=merge(l,fx);
				Ltree[fy].val/=2;
				int r=pop(fy);
				r=merge(r,fy);
				printf("%d\n",Ltree[merge(l,r)].val);
			}
		}
	}
	return 0;
}
int Find(int x)
{
	return Ltree[x].fa==x?x:Find(Ltree[x].fa);
}
int pop(int x)
{
	int l=Ltree[x].l,r=Ltree[x].r,v=Ltree[x].val,f=Ltree[x].fa;
	Ltree[l].fa=l,Ltree[r].fa=r;
	Ltree[x]=node(0,0,f,v,0);
	return merge(l,r);
}
int merge(int l,int r)
{
	if(l==0) return r;
	if(r==0) return l;
	if(Ltree[l].val<Ltree[r].val) swap(l,r);
	Ltree[l].r=merge(Ltree[l].r,r);
	Ltree[Ltree[l].r].fa=l;//l->rs->fa=l!
	if(Ltree[Ltree[l].l].dis<Ltree[Ltree[l].r].dis) swap(Ltree[l].l,Ltree[l].r);
	if(Ltree[l].r==0) Ltree[l].dis=0;
	else Ltree[l].dis=Ltree[Ltree[l].r].dis+1;
	return l;
}

