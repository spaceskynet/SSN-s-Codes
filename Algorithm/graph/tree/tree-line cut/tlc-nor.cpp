/*
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
const int maxn=1e6;
struct edge
{
	int to,next;
}e[maxn<<1];
int M=1,n,d[maxn][3];
int tree[maxn<<2],size[maxn],top[maxn],son[maxn],fa[maxn],dep[maxn],pre[maxn],pos[maxn],tot=0,cnt=0;
void ini();
void dfs(int);//first 
void dfs(int,int);//second
void add(int,int);
void updata(int);
int querymax(int,int);
int queryplus(int,int);
void swap(int &x,int &y);
int find(int,int);
int main()
{
	int T;
    scanf("%d",&T);  
    while(T--)
    {  
        scanf("%d",&n);  
        ini();
        for(int i=1;i<n;i++)  
        {  
            int x,y,z;  
            scanf("%d%d%d",&x,&y,&z);  
            d[i][0]=x,d[i][1]=y,d[i][2]=z;  
            add(x,y);  
            add(y,x);  
        }    
		dep[1]=1;  
        dfs(1);  
        dfs(1,1);
        for(;M<=n+2;M<<=1);
        for(int i=1;i<n;i++)  
        {  
            if(dep[d[i][0]]>dep[d[i][1]])  
            {  
                swap(d[i][0],d[i][1]);  
            }
            updata(pos[d[i][1]],tp);  
        }  
        while(1)  
        {  
            char c[25];  
            scanf("%s",c);  
            if(c[0]=='D') break;  
            int a,b;  
            scanf("%d%d",&a,&b);  
            if(c[0]=='Q')  
            {  
                printf("%d\n",find(a,b));  
            }  
            else  
            {
                updata(pos[d[a][1]],tp);  
            }  
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
	if(~son[s]) dfs(son[s],tp);
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
	cls(pre,-1),cls(son,-1),cls(d,0);
}
void swap(int &x,int &y)
{
	x^=y,y^=x,x^=y;
}
int find(int x,int y)	
{
	int f1=top[x],f2=top[y],tmp=-1;  
    while(f1!=f2)  
    {  
        if(dep[f1]<dep[f2])  
        {  
            swap(f1,f2);  
            swap(x,y);
        }  
        tmp=max(tmp,querymax(pos[f1],pos[x]));
//        cout<<1<<" "<<tmp<<endl;
        x=fa[f1],f1=top[x];
    }  
    if(x==y) return tmp;
    ///两点已经在同一条链上，但是不是同一个点  
    if(dep[x]>dep[y]) swap(x,y);
//    cout<<2<<" "<<max(tmp,querymax(pos[x],pos[y]))<<endl;
    return max(tmp,querymax(pos[son[x]],pos[y]));  
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		tree[rt]=pos[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
void updata(int l,int r,int pos,int val,int rt)
{
	if(l==r)
	{
		tree[pos]=
		return;
	}
}
