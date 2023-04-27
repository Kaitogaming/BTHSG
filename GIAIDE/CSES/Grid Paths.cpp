#include<bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;
char a[1001][1001];
ll dp[1001][1001];
bool check=0;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("Grid Paths.INP","r",stdin);
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(a[i][0]=='.' && check==0)
        {
            dp[i][0]=1;
        }else check=1;
    }
    check=0;
    for(ll j=0;j<n;j++)
    {
        if(a[0][j]=='.' && check==0)
        {
            dp[0][j]=1;
        }else check=1;
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            if(a[i][j]=='*')
            {
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n-1][n-1];
}
