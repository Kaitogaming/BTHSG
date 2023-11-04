#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
using namespace std;
ll a[N];
ll dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("WIRES.INP","r",stdin);
    freopen("WIRES.OUT","w",stdout);
    ll n;
    dp[0]=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll b;
        cin>>b;
        a[b]=i+1;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }
    ll pre=n+1;
    cout<<ans<<endl;
    vector <ll> kq;
    for(ll i=n;i>=1;i--)
    {
        if(dp[i]==ans && a[i]<pre)
        {
            kq.push_back(i);
            ans--;
            pre=a[i];
        }
    }
    reverse(kq.begin(),kq.end());
    for(ll i=0;i<kq.size();i++)
    {
        cout<<kq[i]<<" ";
    }
}
