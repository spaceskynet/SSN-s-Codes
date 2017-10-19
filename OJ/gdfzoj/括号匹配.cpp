//括号匹配的检验程序
#include <cstdio>
#include<iostream>
#include <cstdlib>
#include <cstring>
#define  MAXLEN 50
int sx=0;
typedef struct stack
{
	char ch[50];
	int top;
}ST;
ST *ST_Init()
{
	ST *st;
	if (st=(ST *)malloc(sizeof(ST)))
	{
		st->top=0;
		return st;
	}
	return NULL;
}
int ST_Pop(ST *st)
{
	if (st->top==0)
	{
		return 0;
	}
	st->top--;
	return st->ch[st->top];
}
void st_Push(ST *st,char c)
{
	if (st->top==MAXLEN)
	{
		return ;
	}
	st->ch[st->top]=c;
	st->top++;
}
void check_symbol(ST *st,char *a)
{
	int i;
	st_Push(st,a[0]);
	for (i=1;i<strlen(a);i++)
	{
		if ((a[i]==']'&&st->ch[st->top-1]=='[')||(a[i]==')'&&st->ch[st->top-1]=='(')||(a[i]=='}'&&st->ch[st->top-1]=='{'))//出栈的条件
		{
			ST_Pop(st);
			sx+=2;
		}
		else
		{
			st_Push(st,a[i]);
		}
	}
	/*if(st->top==0)
	{
	}
	else
	{
	}*/
}

int main()
{
	char s[50];
	int n;
	ST *st;
	st=ST_Init();
	scanf("%d%s",&n,s);
	check_symbol(st,s);
	std::cout<<sx<<std::endl;
	return 0;
}

