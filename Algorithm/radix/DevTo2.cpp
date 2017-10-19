#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(int argc,char const *argv[])
{
	int number;
	scanf("%d",&number);
	unsigned mask= 1<<31;
	/*for(;mask;mask>>1)
	{
		printf("%d",number & mask ? 1 : 0);
	}*/
	cout<<mask;
	cout<<endl;
	return 0;
}

