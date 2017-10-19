#include<iostream>
#include<cstdio>
using namespace std;
int ax;
char str[100];
void read();
int main()
{
	read();
	return 0;
}
void read()
{
	bool flag=1;
	int tmp=0;
	scanf("%s",str);
	for(int i=0;i<strlen(str);)
	{
		if(str[i]=='-') 
		{
			while(str[i]<='9'&&str[i]>='0')
			{
				tmp+=tmp*10+str[i]-'0';
				i++;
			}
			tmp*=-1;
		}
		if(str[i])
	}
}