//spaceskynet bzoj2818
#include<iostream>
#include<cstdio>
#include<cmath>
#define P(x) ((x)*(x))
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
typedef double db;
const db eps=1e-3;
db  ax,ay,bx,by,
	cx,cy,dx,dy,
	v0,v1,v2;
db dis(db,db,db,db);
db tim(db,db,db,db,db,db,db,db);
db Find(db,db);
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&v1,&v2,&v0);
	db  lx=ax,rx=bx,midx,mmidx,t1,
		ly=ay,ry=by,midy,mmidy,t2;
	while(abs(rx-lx)>eps||abs(ry-ly)>eps)
	{
		midx=(lx+rx)/2,midy=(ly+ry)/2;
		mmidx=(midx+rx)/2,mmidy=(midy+ry)/2;
		t1=Find(midx,midy),t2=Find(mmidx,mmidy);
		if(t1>t2) lx=midx,ly=midy;
		else rx=mmidx,ry=mmidy;
	}
	printf("%.2f\n",Find(lx,ly));
	return 0;
}
db dis(db x1,db y1,db x2,db y2)
{
	return sqrt(P(x1-x2)+P(y1-y2));
}
db tim(db x1,db y1,db x2,db y2,db x3,db y3,db x4,db y4)
{
	return dis(x1,y1,x2,y2)/v1+dis(x2,y2,x3,y3)/v0+dis(x3,y3,x4,y4)/v2;
}
db Find(db x,db y)
{
	db  lx=cx,rx=dx,midx,mmidx,t1,
		ly=cy,ry=dy,midy,mmidy,t2;
	while(abs(rx-lx)>eps||abs(ry-ly)>eps)
	{
		midx=(lx+rx)/2,midy=(ly+ry)/2;
		mmidx=(midx+rx)/2,mmidy=(midy+ry)/2;
		t1=tim(ax,ay,x,y,midx,midy,dx,dy);
		t2=tim(ax,ay,x,y,mmidx,mmidy,dx,dy);
		if(t1>t2) lx=midx,ly=midy;
		else rx=mmidx,ry=mmidy;
	}	
	return tim(ax,ay,x,y,lx,ly,dx,dy);
}
