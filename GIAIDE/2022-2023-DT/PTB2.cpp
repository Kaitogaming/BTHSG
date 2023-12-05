#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
map<ll,ll> mp;
        ll a[N];
void solve(ll x)
{
    ll ans=0;
    for(ll i=3;i<=n;i++)
    {
        ans+=(i-1)/2;
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PTB2.INP","r",stdin);
    freopen("PTB2.OUT","w",stdout);
    ll n;
    cin>>n;
    ll mx=0;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        mp[a[i]]++;
    }
    if(mx==n)
    {
        solve(n);
        return 0;
    }
    sort(a,a+n);
    ll ans=0;
    for(ll i=0; i<n-2; i++)
    {
        for(ll j=i+1; j<n-1; j++)
        {
            if(a[i]+a[j]>a[n-1]) break;
            ll sum=a[i]+a[j];
            if(mp[sum])
            {
                ans+=2;
            }
        }
    }
    cout<<ans;
}
