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

		string sBinary;//ת����Ķ����ƴ洢Ϊ�ַ�����������Ĭ�Ϲ��캯�����Ի�Ϊ�մ�
		long long temp = abs(iInPut);
		if (temp == 0)
		{
			//cout.width(11);//��11λ�Ŀ���Ҷ������
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
			temp >>= 1;//���������ƣ���λ��0
		}
		reverse(sBinary.begin(), sBinary.end());
		const char *cOutPut = sBinary.c_str();
		cout.width(11);
		cout << iInPut << (iInPut > 0 ? "-->" : "-->-") << cOutPut << endl;
	}
	return 0;
}


