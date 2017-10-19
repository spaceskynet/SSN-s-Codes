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
struct zkw
{
	int num,mx;
//	zkw(int num=0,int mx=-1):num(num),mx(mx){}
}seg[maxn<<1],tp;
int M=1,n,d[maxn][3];
int tree[maxn],size[maxn],top[maxn],son[maxn],fa[maxn],dep[maxn],pre[maxn],pos[maxn],tot=0,cnt=0;
void ini();
void dfs(int,int,int);//first 
void dfs(int,int);//second
void add(int,int);
void updata(int,zkw);
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
		dep[0]=0;  
        dfs(1,1,1);  
        dfs(1,1);
        for(;M<=n+2;M<<=1);
        for(int i=1;i<n;i++)  
        {  
            if(dep[d[i][0]]>dep[d[i][1]])  
            {  
                swap(d[i][0],d[i][1]);  
            }
            tp.mx=tp.num=d[i][2];
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
            	tp.mx=tp.num=b;
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
void dfs(int s,int fat,int dp)
{
	int mxs=0,ito=e[s].to;
	fa[s]=fat,dep[s]=dp;
	size[s]=1,son[s]=0;
	while(ito!=fa[s]&&ito!=son[s])
	{
		dfs(son[s],s,dp+1);
		size[s]+=size[ito];
		if(size[ito]>mxs)
		{
			mxs=size[son[s]];
			son[s]=ito;
		}
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
	int ans=-1;
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
int find(int x,int y)
{
	int tmp=-1;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y),swap(top[x],top[y]);
		}
		tmp=max(tmp,querymax(pos[top[x]],pos[x]));
		x=top[x];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	tmp=max(tmp,querymax(pos[top[x]],pos[x]));
	return tmp;
}
