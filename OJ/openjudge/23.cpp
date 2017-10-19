#include <iostream>
using namespace std;
int main()
{
	int m,n,s=0;
	cin>>m>>n;
	for(;m<=n;m++)
	{
		if(m%17==0)
		{
			s+=m;
		}
	}
	cout<<s;
	return 0;
}
