#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans,dem=0;
ll a[100][100];
ll dp[100][100];
void solve(ll i,ll j,ll curans)
{
    if(i==m-1 && j==n-1)
    {
         if(abs(curans-ans)<=k)
         {
             dem++;
         }
         return;
    }
    if(j<n)
    solve(i,j+1,curans+a[i][j+1]);
    if(i<m)
    solve(i+1,j,curans+a[i+1][j]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DUONGDI.INP","r",stdin);
    freopen("DUONGDI.OUT","w",stdout);
    cin>>m>>n>>k;
    for(ll i=0;i<m;i++)
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
    }
    for(ll i=1;i<m;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for(ll i=1;i<m;i++)
    {
        for(ll j=1;j<n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
//    for(ll i=0;i<m;i++)
//    {
//        for(ll j=0;j<n;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    cout<<dp[m-1][n-1]<<endl;
    ans=dp[m-1][n-1];
    solve(0,0,a[0][0]);
    cout<<dem;
}
