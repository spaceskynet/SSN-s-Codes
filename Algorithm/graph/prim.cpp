#include <iostream>
#include <cstring>
#define maxn 25025048
using namespace std;
int n,m,a[5001][5001]={0},dis[100001]={0};
bool f[100001]={0};
int main()
{
	cin>>n>>m;
	memset(a,25025048,sizeof(a));
	for(int i=1,u,v,d;i<=m;i++)
	{
		cin>>u>>v>>d;
		if(d<a[u][v]) a[u][v]=d,a[v][u]=d;///因为有重边，所以读入时选择最小的边
	}
	memset(dis,25025048,sizeof(dis));
	memset(f,1,sizeof(f));
	f[0]=0;
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int k=0,x=0;
		for(int j=1;j<=n;j++)
			if(f[j]==1&&(dis[j]<dis[k])) k=j; ///找出最小的蓝点
		f[k]=0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==1&&(a[k][j]<dis[j])) dis[j]=a[k][j],x=j;
		}
	}
	int s=0;
	for(int i=1;i<=n;i++)
		s+=dis[i];
	cout<<s<<endl;
	return 0;
}
