#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
ll a[100][100];
ll dp[100][100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BL2.INP","r",stdin);
    freopen("BL2.OUT","w",stdout);
    cin>>n;
    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[2][1]=a[2][1];
    dp[2][2]=a[2][2];
    for(ll i=3;i<=n;i++)
    {
        dp[i][1]=dp[i-1][1]+a[i][1];
        dp[i][i]=dp[i-1][i-1]+a[i][i];
    }
    for(ll i=3;i<=n;i++)
    {
        for(ll j=2;j<i;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,dp[n][i]);
    }
//    for(ll i=2;i<=n;i++)
//    {
//        for(ll j=1;j<=i;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    cout<<ans;

}
