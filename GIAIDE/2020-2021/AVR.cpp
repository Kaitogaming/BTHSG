#include <bits/stdc++.h>
#define ll long long
ll cursum,n,b,i,a;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("AVR.INP","r",stdin);
    freopen("AVR.OUT","w",stdout);
    cin>>n;
    cin>>b;
    cout<<b<<' ';
    cursum+=b;
    for(i=1;i<n;i++)
    {
        cin>>b;
        a=b*(i+1);
        a-=cursum;
        cout<<a<<' ';
        cursum+=a;
    }
}
