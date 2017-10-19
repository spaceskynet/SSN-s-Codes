#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
//#include<iomanip>
#include<algorithm>
//#include<ctime>
#include<map>
//#include<list>
#include<queue>
#include<stack>
using namespace std;
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Global variables

//Definition Function

//Main Function
int main()
{
//	double t1=(double)clock()/CLOCKS_PER_SEC;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	int a,b,c,s[6];
	cin>>a>>b>>c;
	s[0]=a+b*c;
	s[1]=(a+b)*c;
	s[2]=a+b+c;
	s[3]=a*b+c;
	s[4]=a*(b+c);
	s[5]=a*b*c;
	sort(s+0,s+6);
	cout<<s[5]<<endl;
//	double t2=(double)clock()/CLOCKS_PER_SEC;
//	cout<<"Times:"<<(double)t2-t1<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
//DIY Function


