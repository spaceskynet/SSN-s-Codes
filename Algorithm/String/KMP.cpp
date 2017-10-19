#include<iostream>
#include<cstring>
#include<cstdio>
int next[100];
void getnext(char b[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<=strlen(b))
	{
		if(j==0||b[i-1]==b[j-1])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
int kmp(char a[],char b[])
{
	int i=1,j=1;
	while(i<=strlen(a)&&j<=strlen(b))
	{
		if(j==0||a[i-1]==b[j-1])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	if(j>strlen(b)) return i-strlen(b);
	else return 0;
}
int main()
{
	char a[40],b[40];
	printf("要匹配的主串：\n");
	scanf("%s",a);
	printf("要匹配的目标字符串：\n");
	scanf("%s",b);
	getnext(b);
	printf("输出next值：\n");
	for(int i=1;i<=strlen(b);i++)
	printf("%d",next[i]);
	printf("\n");
	printf("%d\n",kmp(a,b));
//	system("pause");
	main();
	return 0;
}

