//spaceskynet 2017-08-07 ZX-segtree kth-big
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int s;//子树个数
	node *ls,*rs;	
}t[maxn*18],*root[maxn];
int n,m,tot=0,sz,a[maxn],b[maxn];
void init();
bool cmp(const int&,const int&);
void build(node*&,node*,int,int,int);
int query(node*,node*,int,int,int);
int main()
{
	init();
	scanf("%d",&m);
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(root[l-1],root[r],1,sz,k));
	}
	return 0;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);//cp function
	sz=unique(b+1,b+n+1)-(b+1);
	root[0]=t;
	t->ls=t->rs=t;
	t->s=0;
	for(int i=1;i<=n;i++)
	{
		build(root[i],root[i-1],1,sz,i);
	}
}
void build(node *&o,node *p,int l,int r,int x)
{
	o=&t[++tot];
	*o=*p;//copy前缀 
	o->s++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(a[x]>=b[mid]) build(o->ls,p->ls,l,mid,x);//pos
	else build(o->rs,p->rs,mid+1,r,x);
}
int query(node *lc,node *rc,int l,int r,int k)
{
	if(l==r) return b[l];
	int mid=(l+r)>>1;
	int add=rc->ls->s-lc->ls->s;
	if(k<=add) return query(lc->ls,rc->ls,l,mid,k);
	else return query(lc->rs,rc->rs,mid+1,r,k-add);
}
bool cmp(const int &a,const int &b){return a>b;}
