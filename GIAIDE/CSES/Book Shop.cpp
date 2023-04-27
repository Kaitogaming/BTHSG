#include <bits/stdc++.h>
#define ll long long
using namespace std;
int w[1005];
int v[1005];
ll n,x;
int dp[1005][100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("BOOKSHOP.INP","r",stdin);
    memset(dp,0,sizeof(dp));
    cin>>n>>x;
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
//    for(ll i=0;i<=n;i++)
//    {
//        dp[i][0]=0;
//    }
//    for(ll i=0;i<=x;i++)
//    {
//        dp[0][i]=0;
//    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-w[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][x];
}
