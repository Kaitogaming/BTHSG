#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll dp[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("B4.INP","r",stdin);
//    freopen("B4.OUT","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
         ll a;
         cin>>a;
         dp[a%m]++;
         ans=max(ans,dp[a%m]);
    }
    cout<<ans;
}
