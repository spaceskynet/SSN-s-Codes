#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,tmp=0,s=-1000000000,a[105][105];
void work();
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n-i;k++)
			{
				for(int l=0;l<n-j;l++)
				{
					for(int b=0;b<=k;b++)
					{
						for(int c=0;c<=l;c++)
						{
							tmp+=a[i+b][j+c];
						}
					}
					if(tmp>s) s=tmp;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
void work()
{
	
}
