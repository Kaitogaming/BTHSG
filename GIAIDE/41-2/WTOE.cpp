#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[105][105];
ll dp[105][105];
ll move1[3]={1,0,-1};
    ll n,m;
bool check(ll x)
{
    return x>=0 && x<m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("WTOE.INP","r",stdin);
    freopen("WTOE.OUT","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<m;i++)
    {
        dp[i][0]=a[i][0];
    }
    for(ll j=1;j<m;j++)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll k=0;k<3;k++)
            {
                ll x=i+move1[k];
                if(check(x)==0) continue;
                dp[i][j]=min(dp[i][j],dp[x][j-1]+a[i][j]);
            }
        }
    }
//    for(ll i=0;i<n;i++)
//    {
//        for(ll j=0;j<m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    ll ans=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        ans=min(ans,dp[i][m-1]);
    }
    cout<<ans<<endl;
}
