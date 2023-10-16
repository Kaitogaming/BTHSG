#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
map<ll,ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("LUCKY.INP","r",stdin);
    freopen("LUCKY.OUT","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll a;
        cin>>a;
        cout<<mp[a]<<endl;
    }
}
