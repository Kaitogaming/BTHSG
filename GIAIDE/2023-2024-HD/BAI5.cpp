#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=55;
using namespace std;
ll w[N];
ll v[N];
ll dp[N];
int main()
{
    ios::sync_with_stdio(0);
//    freopen("BAI5.INP","r",stdin);
//    freopen("BAI5.OUT","w",stdout);
    ll n;
    cin>>n;
    w[0]=0,v[0]=0;
    for(ll i=1;i<=n;i++)
    {
       cin>>w[i]>>v[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(w[i]<=w[j]) continue;
            dp[i]=max(dp[i],dp[j]+v[i]);
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
}
