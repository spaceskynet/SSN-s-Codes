#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int sz,v;
	bool isre;
	node *ch[2],*fa;
	node(int v=0,bool isre=false):v(v),isre(isre){sz=0;ch[0]=ch[1]=fa=NULL;}
	void maintain()
	{
		sz=ch[0]->sz+ch[1]->sz+1;
	}
	void pushdown()
	{
		if(isre)
		{
			isre=false;
			swap(ch[0],ch[1]);
			if(ch[0]) ch[0]->isre^=1;
			if(ch[1]) ch[1]->isre^=1;
		}
	}
};
struct Splay
{
	int tot;
	node p[maxn],*root;
	bool rs(node *o)
	{
		return o->fa->ch[1]==o;
	}
	void newnode(node *&o,int v,node *fa)
	{
		o=&p[++tot];*o=node(v);o->fa=fa;
	}
	void del(node *&o)
	{
		p[--tot]=*o;o=NULL;
	}
	void init()
	{
		tot=0;
		root=NULL;
	}
	void rot(node *o)
	{
		int d=rs(o)^1;
		node *fa=o->fa;
		fa->ch[d^1]=o->ch[d];
		if(o->ch[d]) o->ch[d]->fa=fa;
		if((o->fa=fa->fa)!=NULL) o->fa->ch[o->fa->ch[1]==fa]=o;
		fa->fa=o;o->ch[d]=fa;o->maintain();fa->maintain();
		if(o->fa=NULL) root=o;
	}
	void splay(node *o,node *fa)
	{
		o->pushdown();
		for(;o->fa!=fa;o->fa->pushdown(),rot(o))
			if(o->fa->fa!=fa) rot(rs(o)==rs(o->fa)?o->fa:o);
	}
	void build(int l,int r)
	{
		 
	}
//	void insert(node *o,int v,int pos,node *fa=NULL)
//	{
//		if(root==NULL){newnode(root,v,NULL);return;}
//		o->pushdown();
//		if(o->ch[0]==NULL){}
//		while(o!=NULL&&pos!=(o->ch[0]?o->ch[0]->sz+1:1)) 
//		{
//			if(pos<=o->ch[0]->sz) o=o->ch[0];
//			else
//			{
//				pos-=o->ch[0]->sz+1;
//				o=o->ch[1];
//			}
//			o->pushdown();
//		}
//		if(o==NULL) return;
//		splay(o,NULL);
//		newnode(o,v,NULL);o->ch[0]=root->ch[0];root->ch[0]=NULL;
//		root->fa=o;o->ch[1]=root;root=o;		
//	}
	void rev(int l,int r)
	{
		node *L=find(root,l),*R=find(root,r);
		splay(L,NULL),splay(R,L);
		R->ch[0]->isre^=1;
		R->ch[0]->pushdown();
		splay(R->ch[0],NULL);
	}
	node *find(node *o,int k)
	{
		while(o!=NULL&&k!=o->ch[0]->sz+1) 
		{
			if(k<=o->ch[0]->sz) o=o->ch[0];
			else
			{
				k-=o->ch[0]->sz+1;
				o=o->ch[1];
			}
			o->pushdown();
		}
		return o;
	}
	void out(node *o)
	{
		if(o!=NULL)
		{
			o->pushdown();
			out(o->ch[0]);
			printf("%d ",&o->v);
			out(o->ch[1]);
		}
	}
}sp;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	sp.init();
	for(int i=1;i<=n;i++)
	{
		sp.insert(sp.root,i,i);
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		sp.rev(l,r);
	}
	sp.out(sp.root);
	return 0;
}
