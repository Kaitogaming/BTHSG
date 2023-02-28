#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[101][101];
ll dp[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FOOD.INP","r",stdin);
    freopen("FOOD.OUT","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
//    for(ll i=0;i<n;i++)
//    {
//        for(ll j=0;j<m;j++)
//        {
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    dp[0][0]=a[0][0];
    for(ll i=1;i<n-1;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for(ll i=1;i<m;i++)
    {
        dp[0][i]=dp[0][i-1]+a[0][i];
    }
    for(ll i=1;i<n-1;i++)
    {
        for(ll j=1;j<m-1;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    ll ans=0,cs;
    for(ll i=0;i<n;i++)
    {
        if(dp[n-2][i]+a[n-1][i]>ans)
        {
            ans=dp[n-2][i]+a[n-1][i];
            cs=i+1;
        }
    }
    cout<<ans<<endl;
    vector <ll> way;

    ll i=n-2,j=cs-1;
    way.push_back(cs);
    way.push_back(n-1);
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
