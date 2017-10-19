#include<cstdio>
#include<iostream>
#include<limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>0?(a):(-(a)))
using namespace std;
const int maxn=1e5+10,INF=INT_MAX;
struct node
{
	node *ch[2],*fa;
	int s,v;
	bool isre;
	node(int v=0):v(v){s=1,ch[0]=ch[1]=fa=NULL;}
	int cmp(int k){return k==v?-1:k>v;}
	void maintain()
	{
		s=1;
		if(ch[0]) s+=ch[0]->s;
		if(ch[1]) s+=ch[1]->s;
	}
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
}*p[maxn];
struct Splay
{
	int tot;
	node *root;
	bool rs(node *o)
	{
		return o->fa->ch[1]==o;
	}
	void newnode(node *&o,int v,node *fa)
	{
		o=p[tot++],*o=node(v),o->fa=fa;
	}
	void del(node *&o)
	{
		p[--tot]=o;o=NULL;
	}
	void insert(node *o,int v,node *fa=NULL)
	{
		if(root==NULL){newnode(root,v,NULL);return;}
		while(o!=NULL) fa=o,o=o->ch[v > o->v];
		newnode(o,v,fa);fa->ch[v > fa->v]=o;
		for(fa=o->fa;fa!=NULL;fa=fa->fa) fa->maintain();
		splay(o,NULL);
	}
	void rot(node *o)
	{
		int d=rs(o)^1;
		node *fa=o->fa;
		fa->ch[d^1]=o->ch[d];
		if(o->ch[d]) o->ch[d]->fa=fa;
		if((o->fa=fa->fa)!=NULL) o->fa->ch[o->fa->ch[1] == fa]=o;
		fa->fa=o;o->ch[d]=fa;o->maintain();fa->maintain();
		if(o->fa==NULL) root=o;
	}
	void splay(node *o,node *fa)
	{
		for(;o->fa!=fa;rot(o))
			if(o->fa->fa!=fa) rot(rs(o)==rs(o->fa)?o->fa:o);
	}
	node *find(node *o,int v)
	{
		while(o!=NULL)
		{
			int d=o->cmp(v);
			if(d==-1) return o;
			o=o->ch[d];
		}
		return NULL;
	}
	node *gmax(node *o)
	{
		if(o==NULL) return NULL;
		while(o->ch[1]!=NULL) o=o->ch[1];
		return o;
	}
	node *merge(node *l,node *r)
	{
		if(!l) return r;
		if(!r) return l;
		node *s=gmax(l);
		splay(s,NULL);
		s->ch[1]=r;r->fa=s;s->maintain();
		return s;
	}
	void split(node *o,int v,node *&l,node *&r)
	{
		node *s=find(o,v);
		splay(s,NULL);
		l=s;
		r=s->ch[1];r->fa=NULL;
		l->maintain();
	}
	void rm(node *o,int v)
	{
		node *pos=find(root,v);
		splay(pos,NULL);
		pos=root;del(root);
		root=merge(pos->ch[0],pos->ch[1]);
		if(root!=NULL) root->fa=NULL;
	}
	int rank(node *o,int v)
	{
		int ret=1;
		while(o!=NULL)
		{
			int d=v > o->v,s=o->ch[0]?o->ch[0]->s:0;
			if(d) ret+=s+1;o=o->ch[d];
		}
		return ret;
	}
	int kth(node *o,int k)
	{
		while(o!=NULL)
		{
			int d=o->ch[0]?o->ch[0]->s:0;
			if(k==d+1) return o->v;
			if(k<d+1) o=o->ch[0];
			else k-=d+1,o=o->ch[1];
		}
		return -1;
	}
	int pre(node *o,int v)
	{
		int ret=-INF;
		while(o!=NULL)
		{
			int d=v>o->v;
			if(d) ret=max(ret,o->v);
			o=o->ch[d];
		}
		return ret;
	}
	int sub(node *o,int v)
	{
		int ret=INF;
		while(o!=NULL)
		{
			int d=v<o->v;
			if(d) ret=min(ret,o->v);
			o=o->ch[d^1];
		}
		return ret;
	}
}sp;
int n,op=0,x;
void init();
int main()
{
	freopen("input1.in","r",stdin);
	scanf("%d",&n);
	init();
	while(n--)
	{
		scanf("%d%d",&op,&x);
		switch(op)
		{
			case 1:sp.insert(sp.root,x);break;
			case 2:sp.rm(sp.root,x);break;
			case 3:printf("%d\n",sp.rank(sp.root,x));break;
			case 4:printf("%d\n",sp.kth(sp.root,x));break;
			case 5:printf("%d\n",sp.pre(sp.root,x));break;
			case 6:printf("%d\n",sp.sub(sp.root,x));break;
		}
	}
	return 0;
}
void init()	
{
	sp.root=NULL;
	sp.tot=0;
	for(int i=0;i<=maxn-10;i++) p[i]=new node();
}
