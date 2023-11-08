#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=2e3+5;
using namespace std;
ll a[N];
ll b[N];
ll dp[N][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TICK.INP","r",stdin);
    freopen("TICK.OUT","w",stdout);
    ll n;
    dp[0][0]=0;
    dp[0][1]=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i+1];
    }
    for(ll i=0;i<n-1;i++)
    {
        cin>>b[i+1];
    }
    dp[1][1]=a[1];
    dp[1][0]=0;
    for(ll i=2;i<=n;i++)
    {
        dp[i][1]=min(dp[i-1][1],dp[i-1][0])+a[i];
        dp[i][0]=dp[i-1][1]-a[i-1]+b[i-1];
    }
    vector<ll> kq;
    ll ans=min(dp[n][0],dp[n][1]);
    cout<<ans<<endl;
    ll i=n;
    while(i>0)
    {
        if(dp[i][0]==ans && i>1)
        {
            kq.push_back(i);
            ans-=b[i-1];
            i-=2;
        }else
        {
            ans-=a[i];
            i--;
        }
    }
    reverse(kq.begin(),kq.end());
    for(ll i=0;i<kq.size();i++)
    {
        cout<<kq[i]<<" ";
    }
}
