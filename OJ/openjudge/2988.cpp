#include<iostream>
#include<cstring>
#include<cmath>
#define MAXN 1010
using namespace std;
int dp[MAXN+1][MAXN+1];
char str1[MAXN],str2[MAXN];
int maxx(int a,int b)
{
	return a>b?a:b;
}
int LCSL(int len1,int len2)
{
	int i,j;
	int len=maxx(len1,len2);
	for(i=0;i<=len;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(i=1;i<=len1;i++)
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
			}
		}
	return dp[len1][len2];
}
int main()
{
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str1>>str2;
		int len1=strlen(str1);
		int len2=strlen(str2);
		cout<<abs(LCSL(len1,len2)-len1)<<endl;
	}
	return 0;
}
