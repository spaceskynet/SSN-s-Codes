

/*
����:Airy
��Ŀ:p1082 �߶�����ϰ 3
*/

#include <cstdio>
#include <iostream>

#define lowbit(i) (i & (-i))

using namespace std;

int readint()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}

const int Nmax = 200100;

int N, Q;

long long delta[Nmax]; // delta��ǰ׺��
long long deltai[Nmax]; // delta * i��ǰ׺��
long long sum[Nmax]; // ԭʼǰ׺��

long long Query(long long *array, int pos)
{
	long long temp = 0ll;
	while(pos > 0)
	{
		temp += array[pos];
		pos -= lowbit(pos);
	}
	return temp;
}

void Update(long long *array, int pos, int x)
{
	while(pos <= N)
	{
		array[pos] += x;
		pos += lowbit(pos);
	}
}

int main()
{
	N = readint();Q = readint();
	for(int i = 1; i <= N; ++i)
	{
		int x = readint();
		sum[i] = sum[i - 1] + x;
	}
	while(Q--)
	{
		char op[5];
		scanf("%s",op);
		if(op[0]=='C') // �޸ģ���[l, r]���������x
		{
			int l = readint(), r = readint(), x = readint();
			Update(delta, l, x);
			Update(delta, r+1, -x);
			Update(deltai, l, x * l);
			Update(deltai, r+1, -x * (r+1));
		}
		else // ��ѯ��[l, r]�����
		{
			int l = readint(), r = readint();
			long long suml = sum[l - 1] + l * Query(delta, l - 1) - Query(deltai, l - 1);
			long long sumr = sum[r] + (r + 1) * Query(delta, r) - Query(deltai, r);
			printf("%lld\n", sumr - suml);
		}
	}

	return 0;
}
