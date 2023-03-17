#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMS.INP","r",stdin);
    freopen("SUMS.OUT","w",stdout);
    cin>>n;
    if(n%5)
    {
        cout<<-1;
        return 0;
    }
    if(n<10)
    {
        cout<<-1;
        return 0;
    }
    n/=5;
    for(ll i=n-2;i<=n+2;i++)
    {
        cout<<i<<' ';
    }
}
