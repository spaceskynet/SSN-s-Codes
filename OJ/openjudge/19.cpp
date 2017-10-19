#include <cstdio>
int main()
{
	double a,b,x;
	int y;
	scanf("%lf%lf",&a,&b);
	y=a/b;
	x=a-y*1.0*b;
	printf("%g", x);;
	return 0;
}
