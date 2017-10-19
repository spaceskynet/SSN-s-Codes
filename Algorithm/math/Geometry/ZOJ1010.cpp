#include<iostream>
#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
#define P(x) ((x)*(x))
using namespace std;
const int maxn=1e5+10;
const db PI=acos(-1),eps=1e-8;
int n;
/*-------normal-------*/
db sqr(db x){return x<0.0?0.0:sqrt(x);}
int sgn(db x){return x<-eps?-1:x>eps?1:0;}
bool cp(const db x,const db y){return abs(x-y)<eps?1:0;}
db cvt(db x){return (PI*x)/180.0;}
/*-------point--------*/
struct Pt
{
	db x,y;
	Pt(){}
	Pt(db x,db y):x(x),y(y){}
};
Pt operator - (const Pt a,const Pt b){return Pt(a.x-b.x,a.y-b.y);}
Pt operator + (const Pt a,const Pt b){return Pt(a.x+b.x,a.y+b.y);}
Pt operator * (const Pt a,const db b){return Pt(a.x*b,a.y*b);}
Pt operator * (const db a,const Pt b){return Pt(a*b.x,a*b.y);}
db norm(Pt x){return sqr(P(x.x)+P(x.y));}
db dis(Pt a,Pt b){return norm(a-b);}
db dot(Pt a,Pt b){return a.x*b.x+a.y*b.y;}
db angle(Pt a,Pt b){return acos(dot(a,b)/norm(a)/norm(b));}
db det(Pt a,Pt b){return a.x*b.y-a.y*b.x;}
Pt rot(Pt a,db angle){return Pt(a.x*cos(angle)-a.y*sin(angle),a.x*sin(angle)+a.y*cos(angle));}
/*---------segment------*/
struct Sg
{
	Pt s,t;
	Sg(){}
	Sg(Pt s,Pt t):s(s),t(t){}
	Sg(db x1,db y1,db x2,db y2){Sg(Pt(x1,y1),Pt(x2,y2));}
};
bool PtOnLine(Sg x,Pt y){return !sgn(det(x.s-y,x.t-y));}
bool PtOnSegment(Sg x,Pt y){return !sgn(det(x.s-y,x.t-y))&&dot(x.s-y,x.t-y)<=0;}//<= --> < without s,t
Pt PtLineProj(Sg x,Pt y)
{
	db r=dot(y-x.s,x.t-x.s)/norm(x.t-x.s);
	return x.s+(x.t-x.s)*r;
}
bool LinePos(Sg x,Sg y){return !sgn(det(x.s-x.t,y.s-y.t));}
bool SegPos(Sg x,Sg y)
{
	db c1=det(y.s-x.s,x.t-x.s),c2=det(x.t-x.s,y.t-x.s);
	c3=det(x.s-y.s,y.t-y.s),c4=det(y.t-y.s,x.t-y.s);
	if(c1*c2>=0&&c3*c4>=0) return true;
	return false;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
	}
	return 0;
}
