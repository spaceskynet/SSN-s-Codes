#include<iostream>
using namespace std;
int main()
{
	int n=0,tmp=0,m=0;
	cin>>n;
	while(n)
	{
		cin>>tmp;
		if(tmp!=70) m+=(tmp/70+1);
		else m++;
		n--;
	}
	cout<<m*0.1;
	return 0;
}

