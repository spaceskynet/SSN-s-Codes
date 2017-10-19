#include<iostream>
#include<algorithm>
using namespace std;
struct in
{
	int num;
	int p;
};
struct in a[100000];
void read(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i].num;
		a[i].p=i;
	}
}
long long work(int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].num>a[j].num)
			{
				s++;
			}
			else continue;
		}
	}
	return s;
}
int main()
{
	int n=0;
	cin>>n;
	read(n);
	cout<<work(n);
	return 0;
}
