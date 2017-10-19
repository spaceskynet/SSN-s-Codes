/*-------------------------------------------------
题目描述
对于给定的一个长度为N的正整数数列A[i]，现要将其分成连续的若干段，并且每段和不超过M（可以等于M），问最少能将其分成多少段使得满足要求。
输入输出格式
输入格式：
输入文件divide_a.in的第1行包含两个正整数N，M，表示了数列A[i]的长度与每段和的最大值，第2行包含N个空格隔开的非负整数A[i]，如题目所述。
输出格式：
输出文件divide_a.out仅包含一个正整数，输出最少划分的段数。
输入输出样例
输入样例#1：
5 6
4 2 4 5 1
输出样例#1：
3
说明
对于20%的数据，有N≤10；
对于40%的数据，有N≤1000；
对于100%的数据，有N≤100000，M≤10^9，M大于所有数的最小值，A[i]之和不超过109。
将数列如下划分：
[4][2 4][5 1]
第一段和为4，第2段和为6，第3段和为6均满足和不超过M=6，并可以证明3是最少划分的段数。
-------------------------------------------------*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
//#include<iomanip>
#include<algorithm>
//#include<ctime>
#include<map>
//#include<list>
#include<queue>
#include<stack>
using namespace std;
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class

//Definition Global variables
int a[100001];
//Definition Function

//Main Function
int main()
{
//	double t1=(double)clock()/CLOCKS_PER_SEC;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,tmp,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+0,a+n);
	bool isz=1;
	for(int i=0,j=n-1;i==j||i-1==j;)
	{
		if(isz)
		{
			if(tmp+a[i]>m)
			{
				tmp=0;
				ans++;
			}
			else
			{
				tmp+=a[i];
				isz=!isz;
				i++;
			}
		}
		else
		{
			if(tmp+a[j]>m)
			{
				tmp=0;
				ans++;
			}
			else
			{
				tmp+=a[j];
				isz=!isz;
				j--;
			}
		}
	}
	cout<<ans<<endl;
//	double t2=(double)clock()/CLOCKS_PER_SEC;
//	cout<<"Times:"<<(double)t2-t1<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
//DIY Function


