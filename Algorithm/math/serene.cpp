#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAXN=1e10+10;
bool isnotPrime[MAXN]={0};
int prime[MAXN],numPrime=0;
void createPrime(ll);
int main()
{
	ll n,x,y;
	cin>>n;
	createPrime(n*10);
	isnotPrime[1]=1;
	for(y=n+1;isnotPrime[y];y++);
	printf("%d",y);
	return 0;
}
void createPrime(ll n)
{
	for(ll i=2;i<n;i++)
	{
		if(!isnotPrime[i])
		{
			prime[numPrime++]=i;
		}
		for(ll j=0;i*prime[j]<n&&j<numPrime;j++)
		{
			isnotPrime[i*prime[j]]=1;
			if(!i%prime[j]) break;
		}
	}
}
