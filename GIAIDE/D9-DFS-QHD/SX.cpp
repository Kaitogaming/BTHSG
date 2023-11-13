#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e4+5;
using namespace std;
ll a1[N];
ll b1[N];
ll a[N];
ll b[N];
ll dp[N][2];
ll ed,ed1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SX.INP","r",stdin);
    freopen("SX.OUT","w",stdout);
    ll n;
    cin>>n;
    cin>>a1[0];
    cin>>b1[0];
    cin>>a1[n]>>b1[n];
    for(ll i=1;i<n;i++)
    {
        cin>>a1[i];
    }
    for(ll i=1;i<n;i++)
    {
        cin>>b1[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    dp[0][0]=a1[0];
    dp[0][1]=b1[0];
    for(ll i=1;i<=n;i++)
    {
         dp[i][0]=dp[i-1][0]+a[i];
         dp[i][0]=min(dp[i][0],dp[i-1][1]+b1[i-1]+a[i]);

         dp[i][1]=dp[i-1][1]+b[i];
         dp[i][1]=min(dp[i][1],dp[i-1][0]+a1[i-1]+b[i]);
    }
    ll ans=min(dp[n][0]+a1[n],dp[n][1]+b1[n]);
    cout<<ans;
    string kq;
    if(ans-a1[n]==dp[n][0])
    {
        kq+="1";
        ans-=a1[n];
    }else
    {
        kq+="2";
        ans-=b1[n];
    }
    ll i=n;
    while(i>1)
    {
        if(ans-a[i]==dp[i-1][0])
        {
            ans-=a[i];
            kq+="1";
        }else if(ans-b[i]-a1[i-1]==dp[i-1][0])
        {
            ans-=b[i]+a1[i-1];
            kq+="1";
        }else if(ans-b[i]==dp[i-1][1])
        {
            ans-=b[i];
            kq+="2";
        }else if(ans-a[i]-b1[i-1]==dp[i-1][1])
        {
            ans-=a[i]+b1[i-1];
            kq+="2";
        }
        i--;
    }
    reverse(kq.begin(),kq.end());
    cout<<endl<<kq;
}
