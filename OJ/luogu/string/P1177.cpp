#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
    ios::sync_with_stdio(false);
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a+0,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
