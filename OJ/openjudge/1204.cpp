#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string cha,chb;
	int p=0;
	cin>>cha>>chb;
	p=cha.find(chb);
	cout<<p+1;
	return 0;
}
