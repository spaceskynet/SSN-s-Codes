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
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class
//Definition Global variables
const int MAXN=10000001;
bool isnotPrime[MAXN]={0};
int prime[MAXN],numPrime=0;
//Definition Function
void createPrime(int);
//Main Function
int main()
{
	ios::sync_with_stdio(false);
	int n,m,x;
	cin>>n>>m;
	createPrime(n+1);
	isnotPrime[1]=1;
	for(int i=0;i<m;i++)
	{
		cin>>x;
		if(isnotPrime[x]) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
//DIY Function
void createPrime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(!isnotPrime[i])
		{
			prime[numPrime++]=i;
		}
		for(int j=0;i*prime[j]<n&&j<numPrime;j++)
		{
			isnotPrime[i*prime[j]]=1;
			if(!i%prime[j]) break;
		}
	}
}

