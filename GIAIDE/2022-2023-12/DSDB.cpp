#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s,s1;
ll dp[1005][1005];
ll a[1005];
ll b[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DSDB.INP","r",stdin);
    freopen("DSDB.OUT","w",stdout);
    memset(dp,0,sizeof(dp));
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        dp[i][0]=i;
        dp[0][i]=i;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        b[n+1-i]=a[i];
    }
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<b[i]<<" ";
//    }
//    cout<<endl;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j]+1;
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            if(a[i]==b[j])
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
        }
    }
    cout<<dp[n][n]/2;
}
//1 7 8 1 9
//9 1 8 7 1
