#include <iostream>
using namespace std;
int main()
{
	int n,x=0,y=1,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		m=y;
		y+=x;
		x=m;
	}
	cout<<x;
	return 0;
}
