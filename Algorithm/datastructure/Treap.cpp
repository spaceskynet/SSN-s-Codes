#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int l,r,sz,w,v,rd;//l,r->lson&&rson || v->weight || w -> howmany ||sz -> sontree's sz || rd ->rand weight
	node(){}
	node(int l,int r,int sz,int w,int v,int rd):l(l),r(r),sz(sz),w(w),v(v),rd(rd){}
}t[maxn];
int root=0,ans=0,sz,n;
void PushUP(int);
void lturn(int&);
void rturn(int&);
void del(int&,int);
void insert(int&,int);
int queryrank(int,int);
int querynum(int,int);
void pro(int,int,int&);
void sub(int,int,int&);
int main()
{
	int op,x,pos;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) insert(root,x);
		else if(op==2) del(root,x);
		else if(op==3) printf("%d\n",queryrank(root,x));
		else if(op==4) printf("%d\n",querynum(root,x));
		else if(op==5) pos=0,pro(root,x,pos),printf("%d\n",t[pos].v);
		else pos=0,sub(root,x,pos),printf("%d\n",t[pos].v);
	}
	return 0;
}
void PushUP(int k)
{
	t[k].sz=t[t[k].l].sz+t[t[k].r].sz+t[k].w;
}
void rturn(int &k)
{
	int fa=t[k].l;t[k].l=t[fa].r;t[fa].r=k;t[fa].sz=t[k].sz;PushUP(k);k=fa;
}
void lturn(int &k)
{
	int fa=t[k].r;t[k].r=t[fa].l;t[fa].l=k;t[fa].sz=t[k].sz;PushUP(k);k=fa;
}
void insert(int &k,int x)
{
	if(!k)
	{
		k=++sz;
		t[k]=node(0,0,1,1,x,rand());
		return;
	}
	t[k].sz++;
	if(t[k].v==x) t[k].w++;
	else if(t[k].v<x)//若 t[k].v>x 则成为左大右小 
	{
		insert(t[k].r,x);
		if(t[t[k].r].rd<t[k].rd) lturn(k);
	}
	else
	{
		insert(t[k].l,x);
		if(t[t[k].l].rd<t[k].rd) rturn(k);
	}
}
void del(int &k,int x)
{
	if(k==0) return;
	if(t[k].v==x)
	{
		if(t[k].w>1){t[k].w--,t[k].sz--;return;}
		if(!(t[k].l*t[k].r)) k=t[k].l+t[k].r;
		else if(t[t[k].l].rd<t[t[k].r].rd) rturn(k),del(k,x);
		else lturn(k),del(k,x);
	}
	else if(t[k].v<x) t[k].sz--,del(t[k].r,x);//!!
	else t[k].sz--,del(t[k].l,x);
}
int queryrank(int k,int x)
{
	if(k==0) return 0;
	if(t[k].v==x) return t[t[k].l].sz+1;
	else if(t[k].v<x) return t[t[k].l].sz+t[k].w+queryrank(t[k].r,x);
	else return queryrank(t[k].l,x);
}
int querynum(int k,int x)
{
	if(k==0) return 0;
	if(t[t[k].l].sz>=x) return querynum(t[k].l,x);
	else if(x>t[t[k].l].sz+t[k].w) return querynum(t[k].r,x-(t[t[k].l].sz+t[k].w));
	else return t[k].v;
}
void pro(int k,int x,int &pos)
{
	if(k==0) return;
	if(t[k].v<x) pos=k,pro(t[k].r,x,pos);
	else pro(t[k].l,x,pos);
}
void sub(int k,int x,int &pos)
{
	if(k==0) return;
	if(t[k].v>x) pos=k,sub(t[k].l,x,pos);
	else sub(t[k].r,x,pos);
}
