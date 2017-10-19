#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
using namespace std;
int main()
{
	int CompositeNumFilterV3(int);
	int n,m,c;
	scanf("%d%d",&n,&m);
	/*-------------*/
	int i, j;
	int count = 0;
	char* flag = (char*)malloc( m+1 );
	int mpLen = 2*3*5*7*11*13;
	char magicPattern[2*3*5*7*11*13];
	for (i=0; i<mpLen; i++)
	{
		magicPattern[i++] = 1;
		magicPattern[i++] = 0;
		magicPattern[i++] = 0;
		magicPattern[i++] = 0;
		magicPattern[i++] = 1;
		magicPattern[i] = 0;
	}
	for (i=4; i<=mpLen; i+=5)
		magicPattern[i] = 0;
	for (i=6; i<=mpLen; i+=7)
		magicPattern[i] = 0;
	for (i=10; i<=mpLen; i+=11)
		magicPattern[i] = 0;
	for (i=12; i<=mpLen; i+=13)
		magicPattern[i] = 0;
	int remainder = m%mpLen;
	char* p = flag+1;
	char* pstop = p+m-remainder;
	while (p < pstop)
	{
		memcpy(p, magicPattern, mpLen);
		p += mpLen;
	}
	if (remainder > 0)
	{
		memcpy(p, magicPattern, remainder);
	}
	flag[2] = 1;
	flag[3] = 1;
	flag[5] = 1;
	flag[7] = 1;
	flag[11] = 1;
	flag[13] = 1;   
	int stop = m/13;
	for (i=17; i <= stop; i++)
	{
		if (0 == flag[i]) continue;
		int step = i*2;
		for (j=i*17; j <= m; j+=step)
		{
			flag[j] = 0;
		}
	}
	/*-------------*/
	int l,r;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>m||l<1||r>m||r<1) cout<<"Crossing the line"<<endl;
		else 
		{
			int ans=0;
			if(r==1) cout<<0<<endl;
			else
			{
				for(int i=l>2?l:2;i<=r;i++)
				{
					if(flag[i]) ans++;
				}
				cout<<ans<<endl;
			}
		}
	}
	free(flag);
	return 0;
}
