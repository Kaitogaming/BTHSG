#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const  int N=1e5+5;
using namespace std;
map<ll,ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUM.INP","r",stdin);
    freopen("SUM.OUT","w",stdout);
    ll n;
    cin>>n;
    ll a=0;
    mp[0]++;
    for(ll i=0;i<n;i++)
    {
        ll b;
        cin>>b;
        a+=b;
        mp[a]++;
    }
    ll ans=0;
    map<ll,ll> ::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
         ll b=it->second;
         ans+=(b-1)*b/2;
    }
    cout<<ans;
}
