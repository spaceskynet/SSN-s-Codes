//dfs版
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+10,cha=26;
struct ACautomaton
{
    int next[maxn][cha],fail[maxn],end[maxn],pos[maxn];
    int L,root;
    int newnode()
    {
        for(int i=0;i<cha;i++) next[L][i]=-1;
        end[L]=0;
        return L++;
    }
    ACautomaton()
    {
        L=0;
        root=newnode();
    }
    void insert(char *buf,int x)
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            int &nxt=next[now][buf[i]-'a'];
            if(nxt==-1) nxt=newnode();
            now=nxt;
            end[now]++;//每加入一个串，就给这个串的路径上所有点的end+1，表示它的前缀都又出现了一次，然后dfs把end加到fail指针指向的点上就可以得到答案了
        }
        pos[x]=now;
    }
    void build()
    {
        queue<int> q;
        fail[root]=root;
        for(int i=0;i<cha;i++)
        {
            int &nxt=next[root][i];
            if(nxt==-1) nxt=root;
            else fail[nxt]=root,q.push(nxt);
        }
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0;i<cha;i++)
            {
                int &nxt=next[now][i],&fnxt=next[fail[now]][i];
                if(nxt==-1) nxt=fnxt;
                else fail[nxt]=fnxt,q.push(nxt);
            }
        }
    }
}ac;
struct failTree
{
    struct node
    {
        int to,next;
    }e[maxn];
    int pre[maxn],tot;
    failTree()
    {
        tot=0;
        memset(pre,-1,sizeof(pre));
    }
    void add(int from,int to)
    {
        e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
    }
    void dfs(int s)
    {
        for(int i=pre[s];~i;i=e[i].next) dfs(e[i].to),ac.end[s]+=ac.end[e[i].to];
    }
}tree;
int n;
char s[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        ac.insert(s,i);
    }
    ac.build();
    for(int i=1;i<ac.L;++i)
    {
        tree.add(ac.fail[i],i);
    }
    tree.dfs(0);
    for(int i=1;i<=n;i++) printf("%d\n",ac.end[ac.pos[i]]);
    return 0;
}