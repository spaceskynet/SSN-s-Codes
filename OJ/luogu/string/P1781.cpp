#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct Node
{
	string m;
	int num;
	Node()
	{
		num=0;
	}
}x[20];
int cpr(string str1,string str2);
int cp(Node a,Node b);
int main()
{
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i].m;
		x[i].num=i+1;
	}
	sort(x+0,x+n,cp);
	cout<<x[0].num<<endl<<x[0].m;
	return 0;
}
int cpr(string str1,string str2)
{
	int len1=str1.size(),len2=str2.size();
	if(len1>len2) return 1;
	else if(len1<len2) return 0;
	else
	{
		for(int i=0;i<len1;i++)
		{
			if(str1[i]>str2[i]) return 1;
			if(str1[i]<str2[i]) return 0;
		}
	}
}
int cp(Node a,Node b)
{
	return cpr(a.m,b.m);
}
