#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANTOAN.INP","r",stdin);
    freopen("ANTOAN.OUT","w",stdout);
    ll a[105][105];
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=2;j<=m;j++)
        {
            if(a[i][j]) continue;
            if(a[i+1][j+1] && a[i+1][j] && a[i][j+1] && a[i+1][j-1] && a[i-1][j+1] && a[i-1][j] && a[i][j-1] && a[i-1][j-1])
                cout<<i<<" "<<j<<endl;
        }
    }
}
