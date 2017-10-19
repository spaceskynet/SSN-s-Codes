#include <iostream>
using namespace std;
int main()
{
	int a,n,s=1;
	cin>>a>>n;
	for(int i=1;i<=n;i++)
	{
		s*=a;
	}
	cout<<s;
	return 0;
}
