#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=6e4+4e3+10;
vector<int> v,ps,ans;
int sup[maxn],pup[maxn],topup=-1,a[maxn],vis[maxn]={0},n,cnt=0;
int read();
bool cmp(int,int);
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) v.push_back(read());
	for(int i=0;i<(int)v.size();i++)
	{
		int pos;
		if(i==0||v[i]>v[sup[topup]]) sup[++topup]=i,pos=topup;
		else
		{
			pos=upper_bound(sup,sup+topup,i,cmp)-sup;
			sup[pos]=i;
		}
		if(pos==0) pup[i]=-1;
		else pup[i]=sup[pos-1];
	}
	int id=sup[topup];
	for(int i=topup;i>=0;i--)
	{
		//vis[ps[id]]=true;
		ans.insert(ans.begin(),v[id]);
		id=pup[id];
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
bool cmp(int x,int y)
{
	return v[x]<v[y];
}
