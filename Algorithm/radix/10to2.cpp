#include<iostream>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(int agrc, char *agrv[])
{
	long long iInPut = 0;
	while (cin >> iInPut)
	{

		string sBinary;//转换后的二进制存储为字符串，调用了默认构造函数初试化为空串
		long long temp = abs(iInPut);
		if (temp == 0)
		{
			//cout.width(11);//以11位的宽度右对齐输出
			cout << "          0-->0\n";
			continue;
		}

		while (temp)
		{
			if (temp & 0x01)
			{
				sBinary += '1';
			}
			else
			{
				sBinary += '0';
			}
			temp >>= 1;//对正数右移，高位补0
		}
		reverse(sBinary.begin(), sBinary.end());
		const char *cOutPut = sBinary.c_str();
		cout.width(11);
		cout << iInPut << (iInPut > 0 ? "-->" : "-->-") << cOutPut << endl;
	}
	return 0;
}


