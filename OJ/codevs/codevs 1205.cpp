#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<sstream>
typedef long long ll;
using namespace std;
int main()
{
	string line;
	int i=0;
	getline(cin,line);
	string str[10];
	stringstream ss(line);
	while(ss>>str[i++]);
	for(int j=i-2;j>=0;j--)
	{
		cout<<str[j]<<" ";
	}
	return 0;
}
