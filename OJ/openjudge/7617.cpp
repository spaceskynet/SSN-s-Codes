#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int a[100001];
int comp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int n=0,k=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+0,a+n,comp);
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
