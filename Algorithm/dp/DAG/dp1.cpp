//2017-03-28 spaceskynet 矩形嵌套 dp入门 DAG 
#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1e3+10;
struct marix
{
	int x,y;
	bool operator > (const marix a) const
	{
		return (this->x>a.x)&&(this->y>a.y);
	}
	void swap()
	{
		if(this->x>this->y) this->x^=this->y,this->y^=this->x,this->x^=this->y;	
	}
}f[maxn];
int a[maxn],t,n;
int dp(int);
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&f[i].x,&f[i].y);
			f[i].swap();
		}
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=dp(i),ans=max(ans,a[i]);
		printf("%d",ans);
	}
	return 0;
}
int dp(int i)
{
	int &ans=a[i];
	if(ans>0) return ans;
	ans=1;
	for(int j=1;j<=n;j++)
	{
		if(f[i]>f[j]) ans=max(ans,dp(j)+1);
	}
	return ans;
}
/*
矩形嵌套
时间限制：3000 ms  |           内存限制：65535 KB
难度：4

描述
    有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。

    输入
        第一行是一个正数N(0<N<10)，表示测试数据组数，
        每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个数(n<=1000)
        随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽
    输出
        每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行
    样例输入

        1
        10
        1 2
        2 4
        5 8
        6 10
        7 9
        3 1
        5 8
        12 10
        9 7
        2 2

    样例输出

        5

*/
