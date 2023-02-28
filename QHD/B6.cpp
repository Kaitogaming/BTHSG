#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[101][101];
ll dp[101][101];
vector <int> way;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    cin>>n>>m;
    dp[0][0]=1;
    for(ll i=1;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(ll i=1;i<m;i++)
    {
        dp[0][i]=1;
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n-1][m-1];
}
