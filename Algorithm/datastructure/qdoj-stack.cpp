#include<cstdio>
#include<cstring>
const int maxn=110;
int n,top=0,len;
bool flag=1;
char s[maxn],stack[maxn];
inline bool check(int);
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		memset(s,0,sizeof(s));
		memset(stack,0,sizeof(stack));
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='('||s[i]=='['||s[i]=='{') 
			{
				stack[++top]=s[i];
				continue;
			}
			if(check(i)) top--;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag) printf("True\n");
		else printf("False\n");
	}
	return 0;
}
inline bool check(int x)
{
	return stack[top]=='('&&s[x]==')'||stack[top]=='['&&s[x]==']'||stack[top]=='{'&&s[x]=='}';
}
