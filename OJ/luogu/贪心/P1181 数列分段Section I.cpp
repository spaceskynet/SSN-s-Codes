/*-------------------------------------------------
��Ŀ����
���ڸ�����һ������ΪN������������A[i]����Ҫ����ֳ����������ɶΣ�����ÿ�κͲ�����M�����Ե���M�����������ܽ���ֳɶ��ٶ�ʹ������Ҫ��
���������ʽ
�����ʽ��
�����ļ�divide_a.in�ĵ�1�а�������������N��M����ʾ������A[i]�ĳ�����ÿ�κ͵����ֵ����2�а���N���ո�����ķǸ�����A[i]������Ŀ������
�����ʽ��
����ļ�divide_a.out������һ����������������ٻ��ֵĶ�����
�����������
��������#1��
5 6
4 2 4 5 1
�������#1��
3
˵��
����20%�����ݣ���N��10��
����40%�����ݣ���N��1000��
����100%�����ݣ���N��100000��M��10^9��M��������������Сֵ��A[i]֮�Ͳ�����109��
���������»��֣�
[4][2 4][5 1]
��һ�κ�Ϊ4����2�κ�Ϊ6����3�κ�Ϊ6������Ͳ�����M=6��������֤��3�����ٻ��ֵĶ�����
-------------------------------------------------*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
//#include<iomanip>
#include<algorithm>
//#include<ctime>
#include<map>
//#include<list>
#include<queue>
#include<stack>
using namespace std;
//Definition Macro
#define ll long long
//Definition namespace
using namespace std;
//Definition Struct Or Class

//Definition Global variables
int a[100001];
//Definition Function

//Main Function
int main()
{
//	double t1=(double)clock()/CLOCKS_PER_SEC;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,tmp,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+0,a+n);
	bool isz=1;
	for(int i=0,j=n-1;i==j||i-1==j;)
	{
		if(isz)
		{
			if(tmp+a[i]>m)
			{
				tmp=0;
				ans++;
			}
			else
			{
				tmp+=a[i];
				isz=!isz;
				i++;
			}
		}
		else
		{
			if(tmp+a[j]>m)
			{
				tmp=0;
				ans++;
			}
			else
			{
				tmp+=a[j];
				isz=!isz;
				j--;
			}
		}
	}
	cout<<ans<<endl;
//	double t2=(double)clock()/CLOCKS_PER_SEC;
//	cout<<"Times:"<<(double)t2-t1<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
//DIY Function


