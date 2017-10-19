#include<cstdio>
#include<iostream>
#define min(x,y) ((x)>(y)?(y):(x))  
using namespace std;
const int INF=~0U>>1;
int map[101][101],dis[101][101];
void floyd(int);
int main()
{
	int n,m,a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				map[i][j]=INF;
				dis[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(map[a][b]>c)  
			{  
				map[a][b]=map[b][a]=c;  
				dis[a][b]=dis[b][a]=c;  
			} 
		}
		floyd(n);
	}
	return 0;
}
void floyd(int n)
{
	int i,j,k,mina=INF;  
    for(k=1;k<=n;k++)  
    {  
        for(i=1;i<k;i++)  
        {  
            for(j=1;j<i;j++)  
            {  
                mina=min(dis[i][j]+map[j][k]+map[k][i],mina);  
            }  
        }  
        for(i=1;i<=n;i++)  
        {  
            for(j=1;j<=n;j++)  
            {  
               if(dis[i][j]>(dis[i][k]+dis[k][j]))  
                dis[i][j]=dis[i][k]+dis[k][j];  
            }  
        }  
    }  
    if(mina<INF)  
		printf("%d\n",mina);  
    else  
		printf("No solution.\n");  
}