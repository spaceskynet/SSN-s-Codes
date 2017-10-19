//2017-01-20
#include<cstdio>
const int maxn=1e5+10;
int x,y,z;
int pre[maxn];
int find(int);
void conect(int,int);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)
		{
			conect(x,y);
		}
		else
		{
			int sx=find(x),sy=find(y);
			if(sx==sy) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
int find(int x)
{
	int r=x;
	while(r!=pre[r])
	{
		r=pre[r];
	}
	int i=x,j;
	while(pre[i]!=r)//Â·¾¶Ñ¹Ëõ
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}
void conect(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		pre[fy]=fx;
	}
}
