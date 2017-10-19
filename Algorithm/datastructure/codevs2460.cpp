/*
-------
树链剖分-zkw
-------
size[]数组，用来保存以x为根的子树节点个数
top[]数组，用来保存当前节点的所在链的顶端节点
son[]数组，用来保存重儿子
dep[]数组，用来保存当前节点的深度
fa[]数组，用来保存当前节点的父亲
pre[]数组，邻接表初始化与点相连的第一边
pos[]数组，点在线段树的位置
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=5e4,INF=~0U>>1;
struct edge
{
	int to,next;
}e[maxn<<1];
struct zkw
{
	int num,mx;
}seg[maxn<<1],tp;
int M=1,n;
int tree[maxn],size[maxn],top[maxn],son[maxn],fa[maxn],dep[maxn],pre[maxn],pos[maxn],tot=0,cnt=0;
void ini();
void dfs(int);//first 
void dfs(int,int);//second
void add(int,int);
void updata(int,zkw);
int querymax(int,int);
int queryplus(int,int);
void swap(int &x,int &y);
int findmax(int,int);
int findplus(int,int);
int main()
{
	scanf("%d",&n);  
	ini();
	for(int i=1;i<n;i++)  
	{  
		int x,y;  
		scanf("%d%d",&x,&y);
		add(x,y);  
		add(y,x);  
	}	
	dep[1]=1;  
	dfs(1);
	dfs(1,1);
	for(;M<=n+2;M<<=1);
	for(int i=1;i<=n;i++)  
	{
		int z;
		scanf("%d",&z);
	    tp.mx=tp.num=z;
	    updata(pos[i],tp);  
	}
	int T;
	scanf("%d",&T);
	while(T--)  
	{  
	    char c[25];  
	    scanf("%s",c);
	    int a,b;  
	    scanf("%d%d",&a,&b);  
	    if(c[1]=='M')  
		{  
		    printf("%d\n",findmax(a,b));
		}
		else if(c[1]=='S')
		{
			printf("%d\n",findplus(a,b));
		}
	    else  
		{
			tp.mx=tp.num=b;
			updata(pos[a],tp);  
		}  
	}  
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
void dfs(int s)
{
	size[s]=1,son[s]=0;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito==fa[s]) continue;
		fa[ito]=s;
		dep[ito]=dep[s]+1;
		dfs(ito);
		if(size[ito]>size[son[s]]) son[s]=ito;
		size[s]+=size[ito];
	}
}
void dfs(int s,int tp)
{
	top[s]=tp;
	pos[s]=++cnt;
	if(son[s]) dfs(son[s],tp);//son[i]==0表示无重儿子 
	for(int i=pre[s];~i;i=e[i].next)
	{
		int &ito=e[i].to;
		if(ito!=son[s]&&ito!=fa[s])
		{
			dfs(ito,ito);
		}
	}
}
inline void ini()
{
	cls(pre,-1),cls(son,0);
}
void updata(int pos,zkw val)
{
	seg[pos+=M]=val;
	while(pos>>=1)
	{
		seg[pos].num=seg[pos<<1].num+seg[pos<<1|1].num;
		seg[pos].mx=max(seg[pos<<1].mx,seg[pos<<1|1].mx);
	}
}
int querymax(int l,int r)
{
	int ans=-INF;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans=max(ans,seg[l^1].mx);
		if(r&1) ans=max(ans,seg[r^1].mx);
	}
	return ans;
}
int queryplus(int l,int r)
{
	int ans=0;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans+=seg[l^1].num;
		if(r&1) ans+=seg[r^1].num;
	}
	return ans;
}
void swap(int &x,int &y)
{
	x^=y,y^=x,x^=y;
}
int findmax(int x,int y)	
{
	int f1=top[x],f2=top[y],tmp=-INF;  
    while(f1!=f2)  
	{  
	    if(dep[f1]<dep[f2])  
		{  
		    swap(f1,f2);  
		    swap(x,y);
		}  
	    tmp=max(tmp,querymax(pos[f1],pos[x]));
	    x=fa[f1],f1=top[x];
	}  
    if(dep[x]>dep[y]) swap(x,y);
    return tmp=max(tmp,querymax(pos[x],pos[y]));  
}
int findplus(int x,int y)	
{
	int f1=top[x],f2=top[y],tmp=0;  
    while(f1!=f2)  
	{  
	    if(dep[f1]<dep[f2])  
		{  
		    swap(f1,f2);  
		    swap(x,y);
		}
	    tmp+=queryplus(pos[f1],pos[x]);
	    x=fa[f1],f1=top[x];
	}  
    if(dep[x]>dep[y]) swap(x,y);
    return tmp+=queryplus(pos[x],pos[y]);  
}
//错误的答案。得分0 On line 3089 column 2, read 1, expected 4919.
