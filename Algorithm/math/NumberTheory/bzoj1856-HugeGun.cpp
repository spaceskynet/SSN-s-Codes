#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define rre(i,r,l) for(int i=(r);i>=(l);i--)
#define re(i,l,r) for(int i=(l);i<=(r);i++)
#define Clear(a,b) memset(a,b,sizeof(a))
#define inout(x) printf("%d",(x))
#define douin(x) scanf("%lf",&x)
#define strin(x) scanf("%s",(x))
#define LLin(x) scanf("%lld",&x)
#define op operator
#define CSC main
typedef unsigned long long ULL;
typedef const int cint;
typedef long long LL;
using namespace std;
void inin(int &ret)
{
    ret=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9')ret*=10,ret+=ch-'0',ch=getchar();
    ret=f?-ret:ret;
}
int n,m;
const LL mod=20100403;
LL inv(LL a,LL n)
{
    a%=n;
    LL b=n-2,ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%n;
        b>>=1;
        a=a*a%n;
    }
    return ret;
}
LL C(int a,int b)
{
    LL x=a;
    re(i,2,b)x=x*(a-i+1)%mod*inv(i,mod)%mod;
    return x;
}
int CSC()
{
	freopen("a.in","r",stdin);
    inin(n),inin(m);
    printf("%lld",((C(n+m,n)-C(n+m,m-1))%mod+mod)%mod);
    return 0;
}
