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
int m,n,w[110][110];
//Definition Function

//Main Function
int main()
{
	ios::sync_with_stdio(false);
	while(1)
	{
		cin>>n;
		if(n==0) break;
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>w[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]+=min(w[i-1][j],w[i][j-1]);
		cout<<w[n][n]%1000000009<<endl;
	}
	return 0;
}
//DIY Function

