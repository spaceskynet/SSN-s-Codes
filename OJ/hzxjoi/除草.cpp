#include<iostream>
#include<cstdio>
#include<cmath>
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class
struct xl
{
	double angel,dis,x,y;
}cdtot,cdnow;
//Definition Global variables
//Definition Function
//Main Function
int main()
{
	const double pi=acos(-1);
    const double conv=pi/180;
	int n=0;
	scanf("%d",&n);
	cdtot.angel=cdtot.x=cdtot.y=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&cdnow.angel,&cdnow.dis);
		cdtot.angel+=cdnow.angel;
		cdtot.angel=fmod(cdtot.angel,360);
		cdtot.y+=sin(cdtot.angel*conv)*cdnow.dis;
		cdtot.x+=cos(cdtot.angel*conv)*cdnow.dis;
	}
	printf("%.2lf %.2lf",cdtot.x+1e-8,cdtot.y+1e-8);
	return 0;
}


