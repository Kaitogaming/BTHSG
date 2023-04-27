#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,i,tong=1;
    int a[200000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            tong+=1;
        }
    }
    cout<<tong;
}
