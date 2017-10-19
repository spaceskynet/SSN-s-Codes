#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn],N;
struct node
{
	node *ch[2],*fa;
	int s,v;
	bool isre;
	node(bool isre=false):isre(isre){}
	int cmp(int k)
	{
		int d=k-ch[0]->s;
		if(d==-1) return -1;
		else return d<=0?0:1;
	}
	void maintain()
	{
		this->s=ch[0]->s+ch[1]->s+1;
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
};
node *null=new node();
struct Splay
{
	int n;//点个数 
	node p[maxn];
	node *root;
//	node *build(int sz)
//	{
//		if(!sz) return null;
//		node *l=build(sz/2);
//		node *o=&p[++n];
//		o->v=a[n];//原序列
//		o->ch[0]=l;l->fa=o;
//		o->ch[1]=build(sz-sz/2-1);o->ch[1]->fa=o;
//		o->s=o->isre=0;
//		o->maintain();
//		return o;
//	}
	void init()
	{
		n=0;
		null->s=0;
		root=&p[++n];
		root->fa=null;
	}
}sp;
node *del(node *o,int v);
node *find(node *o,int v);
node *getpre(node *o,int v);
node *getsuc(node *o,int v);
node *gmax(node *o);
node *gmin(node *o);
node *kth(node *o,int k);
node *merge(node *l,node *r);
void insert(node *o,int v);
void rot(node *&o,int d);
void splay(node *&o,int k);
void split(node *o,int k,node *&l,node *&r);
int main()
{
	scanf("%d",&N);
	sp.init();
	scanf("%d",&a[1]);
	insert(sp.root,a[1]);
	int sum=a[1];
	for(int i=2;i<=N;i++)
	{
		scanf("%d",&a[i]);
		if(find(sp.root,a[i])==null)
		{
			insert(sp.root,a[i]);
			node *l=getpre(sp.root,a[i]),*r=getsuc(sp.root,a[i]);
			int mi=~0U>>1;
			if(l!=null) mi=min(mi,abs(l->v-a[i]));
			if(r!=null) mi=min(mi,abs(r->v-a[i]));
			sum+=mi;
		}	insert(sp.root,a[i]);
			
	}             
	printf("%d\n",sum);
	return 0;
}
void rot(node *&o,int d)
{
	node *s=o->ch[d^1];
	o->ch[d^1]=s->ch[d];
	s->ch[d]->fa=o;//fa
	s->ch[d]=o;
	s->fa=o->fa;//fa
	o->fa=s;//fa
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
		int k2=d2?k-p->ch[0]->s-1:k;
		if(~d2)
		{
			splay(p->ch[d2],k2);
			if(d==d2) rot(o,d^1);
			else rot(o->ch[d],d);
		}
		rot(o,d^1);
	}
}
node *merge(node *l,node *r)//合并后更新root  
{
	splay(l,l->s);
	l->ch[1]=r;
	r->fa=l;
	l->maintain();
	return l;
}
void split(node *o,int k,node *&l,node *&r)
{
	splay(o,k);
	l=o;
	r=o->ch[1];
	o->ch[1]=r->fa=null;
	l->maintain();
}
void insert(node *o,int v)
{
	if(o==null) 
	{
		o=&sp.p[++sp.n];
		o->ch[0]=s->ch[1]=null;
		o->maintain();
		o->fa=o;
		o->v=v;
	}
	while(true)
	{
		o->s++;
		int d=o->v>=v?0:1;
		node *s=o->ch[d];
		if(s!=null) o=s;
		else
		{
			s=&sp.p[++sp.n];
			s->ch[0]=s->ch[1]=null;
			s->maintain();
			s->fa=o;
			s->v=v;
			splay(sp.root,s->s);
			return;
		}
	}
//	while(S!=NULL){
//		p=s;
//		s=s->ch[s->fa->ch[1]==s];
//	}
}
node *getpre(node *o,int v)
{
	splay(o,find(o,v)->s);
	return gmax(o);
}
node *getsuc(node *o,int v)
{
	splay(o,find(o,v)->s);
	return gmin(o);
}
int getrank(node *o,int v)
{
	splay(o,find(o,v)->s);
	return o->ch[0]->s;
}
node *gmax(node *o)
{
	while(o!=null) o=o->ch[1];
	return o;
}
node *gmin(node *o)
{
	while(o!=null) o=o->ch[0];
	return o;
}
node *find(node *o,int v)
{
	while(true)
	{
		if(o->v==v) return o;
		int d=o->v>v?0:1;
		node *s=o->ch[d];
		if(s!=null) o=s;
		else return s;
//		int d=o->cmp();
	}
}
node *del(node *o,int v)//del后更新root 
{
	splay(o,find(o,v)->s);
	return merge(o->ch[0],o->ch[1]);
}
node *kth(node *o,int k)
{
	k++;
	while(true)
	{
		if(o->ch[0]->s==k-1) return o;
		if(o->ch[0]->s>=k) o=o->ch[0];
		else k-=o->ch[0]->s+1,o=o->ch[1];
	}
}
