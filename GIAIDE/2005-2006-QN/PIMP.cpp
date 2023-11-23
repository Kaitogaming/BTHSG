#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[20][20];
ll dp[20][20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("PIMP.INP","r",stdin);
//    freopen("PIMP.OUT","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    ll n,cnt=0;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(i==j) cnt+=a[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        dp[i][1]=0;
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll k=1;k<=n;k++)
            {
                if(k==j) continue;
                dp[j][i]=min(dp[j][i],dp[k][i-1]+a[j][k]);
            }
        }
    }
    ll mn=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        //cout<<dp[i][n]<<" ";
        mn=min(mn,dp[i][n]);
    }
    cout<<mn+cnt;
}
