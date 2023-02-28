#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[101][101];
ll dp[101][101];
vector <int> way;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[0][0]=a[0][0];
    for(ll i=1;i<n;i++)
    {
        dp[0][i]=dp[0][i-1]+a[0][i];
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    ll i=n-1,j=n-1;
    way.push_back(j+1);
    way.push_back(i+1);
    while(i>=0 && j>=0)
    {
        if(i==0 && j==0) break;
        if(dp[i][j]-a[i][j]==dp[i-1][j])
        {
            i--;
            way.push_back(j+1);
            way.push_back(i+1);
        }else
        {
            j--;
            way.push_back(j+1);
            way.push_back(i+1);
        }
    }
    for(ll i=way.size()-1;i>=0;i=i-2)
    {
        cout<<way[i]<<' '<<way[i-1]<<endl;
    }
}
