/** 
spoj375 树链剖分（单点更新，区间查询） 
参考： 
http://blog.sina.com.cn/s/blog_7a1746820100wp67.html 
总结的很经典，树链剖分的第一题建议从它开始 
*/  
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  
///#define debug  
using namespace std;  
const int maxn=10005;  
int fa[maxn],siz[maxn],son[maxn],num[maxn],top[maxn],dep[maxn];  
int tree[maxn*4],d[maxn][3];  
int n,z;  
int head[maxn],ip;  
void init()  
{  
    memset(head,-1,sizeof(head));  
    ip=0;  
}  
  
struct note  
{  
    int v,w,next;  
}edge[maxn*2];  
  
void addedge(int u,int v,int w)  
{  
    edge[ip].v=v,edge[ip].w=w,edge[ip].next=head[u],head[u]=ip++;  
}  
  
void dfs(int u,int pre)  
{  
    son[u]=0,siz[u]=1;  
    dep[u]=dep[pre]+1;  
    fa[u]=pre;  
    for(int i=head[u];i!=-1;i=edge[i].next)  
    {  
        int v=edge[i].v;  
        if(v==pre)continue;  
        dfs(v,u);  
        if(siz[v]>siz[son[u]])  
            son[u]=v;  
        siz[u]+=siz[v];  
    }  
    #ifdef debug  
    printf("%d:siz,son,dep,fa %d %d %d %d\n",u,siz[u],son[u],dep[u],fa[u]);  
    #endif  
}  
  
void build(int u,int tp)  
{  
     num[u]=++z,top[u]=tp;  
     if(son[u]!=0)  
     {  
        build(son[u],top[u]);  
     }  
     for(int i=head[u];i!=-1;i=edge[i].next)  
     {  
        int v=edge[i].v;  
        if(v==fa[u]||v==son[u])continue;  
        build(v,v);  
     }  
     #ifdef debug  
     printf("%d num,top %d %d\n",u,num[u],top[u]);  
     #endif // debug  
}  
  
void update(int root,int l,int r,int loc,int x)  
{  
    if(l>loc||r<loc)return;  
    if(l==r)  
    {  
        tree[root]=x;  
        return;  
    }  
    int mid=(l+r)>>1;  
    update(root<<1,l,mid,loc,x);  
    update(root<<1|1,mid+1,r,loc,x);  
    tree[root]=max(tree[root<<1],tree[root<<1|1]);  
    #ifdef debug  
    printf("root,l,r,tree[root]%d %d %d %d\n",root,l,r,tree[root]);  
    #endif // debug  
}  
  
int maxi(int root,int l,int r,int a,int b)  
{  
    if(r<a||l>b)return 0;  
    if(b>=r&&a<=l)  
    {  
        return tree[root];  
    }  
    int mid=(l+r)>>1;  
    return max(maxi(root<<1,l,mid,a,b),maxi(root<<1|1,mid+1,r,a,b));  
}  
int find(int va,int vb)  
{  
    int f1=top[va],f2=top[vb],tmp=0;  
    while(f1!=f2)  
    {  
        if(dep[f1]<dep[f2])  
        {  
            swap(f1,f2);  
            swap(va,vb);  
        }  
        tmp=max(tmp,maxi(1,1,z,num[f1],num[va]));
//        cout<<1<<" "<<tmp<<endl;
        va=fa[f1],f1=top[va];  
    }  
    if(va==vb)return tmp;  
    ///两点已经在同一条链上，但是不是同一个点  
    if(dep[va]>dep[vb])swap(va,vb);  
//    cout<<2<<" "<<max(tmp,maxi(1,1,z,num[son[va]],num[vb]))<<endl;
    return max(tmp,maxi(1,1,z,num[son[va]],num[vb]));  
}  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        init();  
        memset(d,0,sizeof(d));  
        for(int i=1;i<n;i++)  
        {  
            int x,y,z;  
            scanf("%d%d%d",&x,&y,&z);  
            d[i][0]=x,d[i][1]=y,d[i][2]=z;  
            addedge(x,y,z);  
            addedge(y,x,z);  
        }  
        int root=(n+1)>>1;  
        z=0,dep[0]=0;  
        dfs(root,0);  
        build(root,root);  
        for(int i=1;i<n;i++)  
        {  
            if(dep[d[i][0]]>dep[d[i][1]])  
            {  
                swap(d[i][0],d[i][1]);  
            }  
            update(1,1,z,num[d[i][1]],d[i][2]);  
        }  
        while(1)  
        {  
            char c[25];  
            scanf("%s",c);  
            if(c[0]=='D')break;  
            int a,b;  
            scanf("%d%d",&a,&b);  
            if(c[0]=='Q')  
            {  
                printf("%d\n",find(a,b));  
            }  
            else  
            {  
                update(1,1,z,num[d[a][1]],b);  
            }  
        }  
    }  
    fclose(stdin);
    fclose(stdout);
    return 0;  
} 
