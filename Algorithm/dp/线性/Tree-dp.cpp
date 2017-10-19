#include<cstdio>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
const int maxn=6e3+10;
struct edge
{
	int to,next;
}e[maxn];
int f[maxn][2],pre[maxn],tot=0,val[maxn],F,T,fa[maxn],root;
void add(int,int);
int main()
{
	cls(pre,-1),cls(fa,-1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]),f[i][0]=0,f[i][1]=val[i];
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&F,&T);
		fa[F]=T;
		add(T,F);
	}
	for(int i=1;i<=n;i++) if(!(~fa[i])) root=i;
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}

