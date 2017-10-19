#include<cstdio>
int main()
{
	double num[3];
	bool flag=1;
	scanf("%lf%lf",&num[0],&num[1]);
	num[3]=num[0]>num[1]?(num[0]-num[1]):(num[1]-num[0]);
	if(num[3]>1e-8) flag=0;
	if(flag) printf("yes");
	else printf("no");
	return 0;
}
