#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int l,r,v,w,rd,sz;
	node(){}
	node(int l,int r,int v,int w,int rd,int sz):l(l),r(r),v(v),w(w),rd(rd),sz(sz){}
}t[maxn];
int root=0,sz=0,n,mi,now=0,tot=0,lv=0;
void PushUP(int);
void lturn(int&);
void rturn(int&);
int del(int&,int);
void insert(int&,int);
int getsum(int&,int);
int main()
{
	int x;
	char op[2];
	scanf("%d%d",&n,&mi);
	while(n--)
	{
		scanf("%s%d",op,&x);
		if(op[0]=='I')
		{
			if(x>=mi) insert(root,x-now);
		}
		else if(op[0]=='A') now+=x;
		else if(op[0]=='S')
		{
			now-=x;
			lv+=del(root,mi-now);
		}
		else
		{
			if(x<=t[root].sz) printf("%d\n",getsum(root,t[root].sz-x+1)+now);
			else printf("-1\n");
		}
	}
	printf("%d\n",lv);
	return 0;
}
void PushUP(int k)
{
	t[k].sz=t[t[k].l].sz+t[t[k].r].sz+t[k].w;
}
void lturn(int &k)
{
	int fa=t[k].r;t[k].r=t[fa].l;t[fa].l=k;t[fa].sz=t[k].sz;PushUP(k);k=fa;
}
void rturn(int &k)
{
	int fa=t[k].l;t[k].l=t[fa].r;t[fa].r=k;t[fa].sz=t[k].sz;PushUP(k);k=fa;
}
void insert(int &k,int x)
{
	if(!k)
	{
		k=++sz;
		t[k]=node(0,0,x,1,rand(),1);
		return;
	}
	t[k].sz++;
	if(t[k].v==x) t[k].w++;
	else if(t[k].v>x)
	{
		insert(t[k].l,x);
		if(t[t[k].l].rd<t[k].rd) rturn(k);
	}
	else
	{
		insert(t[k].r,x);
		if(t[t[k].r].rd<t[k].rd) lturn(k);
	}
}
int getsum(int &k,int x)
{
	if(k==0) return 0;
	if(x<=t[t[k].l].sz) return getsum(t[k].l,x);
	else if(x>t[t[k].l].sz+t[k].w) return getsum(t[k].r,x-(t[t[k].l].sz+t[k].w));
	else return t[k].v;
}
int del(int &k,int x)
{
	int tp;
	if(k==0) return 0;
	if(t[k].v<x) return t[t[k].l].sz+t[k].w+del(k=t[k].r,x);
	else return tp=del(t[k].l,x),t[k].sz-=tp,tp;
}
