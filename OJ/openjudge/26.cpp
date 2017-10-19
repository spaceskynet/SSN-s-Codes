#include <iostream>
using namespace std;
int main()
{
	int n,a,H=0,i=0,g,s,b,q;
	cin>>n;
	while(i<n)
	{
		i++;
		cin>>a;
		g=a%10;
		a/=10;
		s=a%10;
		a/=10;
		b=a%10;
		a/=10;
		q=a;
		a=0;
		(g-q-s-b)>0?H++:H+=0;
	}
	cout<<H;
	return 0;
}
