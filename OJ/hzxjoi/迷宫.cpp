#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
//Definition Macro
#define ll long long
#define MAXN 1010
//Definition namespace
using namespace std;
//Definition Struct Or Class
struct point
{
	int x,y;
}record[10],start;//记录点，起点
typedef struct Stat
{
    Stat(int _x,int _y,int _distance):x(_x),y(_y),distance(_distance){}
    int x,y;
    int distance;
}Stat;
//Definition Global variables
bool Map[MAXN][MAXN]={0};//bool存迷宫
int whereto[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};//上下左右四个方向
queue<Stat> ischecking;//比较队列
int Mark[MAXN][MAXN];//标记是否来过
bool isFind=0;
int n,m,k;
//Definition Function
int bfs(int,int);
bool isrecord(int,int,int,int);
//Main Function
int main()
{
//	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>Map[i][j];
		}
	}
	for(int i=0;i<k;i++)
	{
		cin>>record[i].x>>record[i].y;
	}
	cin>>start.x>>start.y;
	Stat stat(start.x-1,start.y-1,0);
    memset(Mark,0,sizeof(Mark));
    Mark[start.x-1][start.y-1]=1;
    ischecking.push(stat);
    int ans=bfs(record[0].x-1,record[0].y-1);
    while(ischecking.size()) ischecking.pop();
    isFind=0;
    if(ans==-1) cout<<ans<<endl;
	else
	{
		int tmp=0;
		for(int i=0;i<k-1;i++)
	    {
			Stat stat(record[i].x-1,record[i].y-1,0);
			memset(Mark,0,sizeof(Mark));
		    Mark[record[i].x-1][record[i].y-1]=1;
		    ischecking.push(stat);
		    int tmp=bfs(record[i+1].x-1,record[i+1].y-1);
		    while(ischecking.size()) ischecking.pop();
		    isFind=0;
		    if(tmp==-1)
		    {
		    	cout<<"-1"<<endl;
		    	return 0;
			}
			else
			{
				ans+=tmp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//DIY Function
int bfs(int EndX,int EndY)
{
    while(!ischecking.empty())
    {
        Stat stat = ischecking.front();
        ischecking.pop();
        for(int i=0;i<4;i++)
        {
            int NextX=stat.x+whereto[i][0];
            int NextY=stat.y+whereto[i][1];
            if(NextX<0||NextX>=n||NextY<0||NextY>=m)
            {
                continue;
            }
            if(Mark[NextX][NextY])
            {
                continue;
            }
            if(Map[NextX][NextY]||isrecord(NextX,NextY,EndX,EndY))
            {
                continue;
            }
            Stat newStat(NextX,NextY,stat.distance+1);
			Mark[NextX][NextY]=1;
			ischecking.push(newStat);
            if(NextX==EndX&&NextY==EndY)
            {
                return newStat.distance;
            }
        }
    }
    return -1;
}
bool isrecord(int x,int y,int EndX,int EndY)
{
	for(int i=0;i<k;i++)
	{
		if(x==record[i].x&&y==record[i].y&&x!=EndX&&y!=EndY)
		{
			return 1;
		}
	}
	return 0;
}
