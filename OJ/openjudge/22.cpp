#include <iostream>
using namespace std;
int main()
{
	int s;
	double b,w;
	cin>>s;
	b=50+s/3.0;
	w=s/1.2;
	if(b>w) cout<<"Walk";	
	else if(b<w) cout<<"Bike";
	else cout<<"All";
	return 0;
}
