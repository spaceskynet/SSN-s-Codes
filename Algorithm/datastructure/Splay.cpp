//spaceskynet 2017-08-08 Splay
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int sz;
vector<int> ans;
struct node
{
	node *ch[2];
	int s,id;
	bool isre;
	node(bool isre=false):isre(isre){}
	int cmp(int k)
	{
		int d=k-ch[0]->s;
		if(d==1) return -1;//is root
		return d<=0?0:1;
	}
	void maintain(){this->s=ch[0]->s+ch[1]->s+1;}
	void pushdown()
	{
		if(isre)
		{
			isre=false;
			swap(ch[0],ch[1]);
			ch[0]->isre^=1;
			ch[1]->isre^=1;
		}
	}
};
node *null=new node();
struct Splay
{
	int n;
	node p[maxn];
	node *root;
	node *build(int sz)
	{
		if(!sz) return null;
		node *l=build(sz/2);
		node *o=&p[++n];
		o->id=n;
		o->ch[0]=l;
		o->ch[1]=build(sz-sz/2-1);
		o->s=o->isre=0;
		o->maintain();
		return o;
	}
	void init(int sz)
	{
		n=0;
		null->s=0;
		root=build(sz);
	}
}sp;
int n,m;
void rot(node*&,int);
void splay(node*&,int);
node *merge(node*,node*);
void split(node*,int,node*&,node*&);
void out(node*);
int main()
{
	int l,r;
	scanf("%d%d",&n,&m);
	sp.init(n+1);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		node *L,*R,*M,*o;
		split(sp.root,l,L,o);
		split(o,r-l+1,M,R);
		M->isre^=1;
		sp.root=merge(merge(L,R),M);
	}
	out(sp.root);
	for(int i=1;i<ans.size();i++)
	{
		printf("%d\n",ans[i]);
	}
	delete null;
	return 0;
}
void rot(node *&o,int d)
{
	node *s=o->ch[d^1];
	o->ch[d^1]=s->ch[d];
	s->ch[d]=o;
	o->maintain();
	s->maintain();
	o=s;
}
void splay(node *&o,int k)
{
	o->pushdown();
	int d=o->cmp(k);
	if(d==1) k-=o->ch[0]->s+1;
	if(~d)
	{
		node *p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k);
		int k2=(d2==0?k:k-p->ch[0]->s-1);
		if(~d2)
		{
			splay(p->ch[d2],k2);
			if(d==d2) rot(o,d^1);
			else rot(o->ch[d],d);
		}
		rot(o,d^1);
	}
}
node *merge(node *l,node *r)
{
	splay(l,l->s);
	l->ch[1]=r;
	l->maintain();
	return l;
}
void split(node *o,int k,node *&l,node *&r)
{
	splay(o,k);
	l=o;
	r=o->ch[1];
	o->ch[1]=null;
	l->maintain();
}
void out(node *o)
{
	if(o!=null)
	{
		o->pushdown();
		out(o->ch[0]);
		ans.push_back(o->id-1);
		out(o->ch[1]);
	}
}
