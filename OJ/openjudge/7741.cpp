#include<iostream>
using namespace std;
int a[6][6]={0},b[6]={0,1,2,3,4,5},x,y;
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>x>>y;
	b[y]=x;
	b[x]=y;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cout<<a[b[i]][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}


