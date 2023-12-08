#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e4+5,M=505;
using namespace std;
ll a[N];
ll dp[N][M];
ll n ,m;
ll solve(ll id,ll cur)
{
    if(id==n+1)
    {
        return 0;
    }
    if(dp[id][cur]!=-1) return dp[id][cur];
    ll ans=INT_MAX;
    if(cur>0)
    {
        ans=solve(id+cur,0);
    }else if(cur==0)
    {
        ans=solve(id+1,cur);
    }

    if(cur<m && n-id>cur)
    {
        ans=max(ans,solve(id+1,cur+1)+a[id]);
    }
    return dp[id][cur]=ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("running.inp","r",stdin);
    freopen("running.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(0,0);
}
////10 5
////2 3 1 5 4 2 1 3 2 1
//#include <bits/stdc++.h>
//#define ll long long
//#define endl "\n"
//const int N=1e4+5,M=5e2+5;
//using namespace std;
//ll dp[N][M];
//ll a[N];
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
////    freopen("running.inp","r",stdin);
////    freopen("running.out","w",stdout);
//    memset(dp,-1,sizeof(dp));
//    ll n,m;
//    cin>>n>>m;
//    for(ll i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    dp[0][0]=0;
//    for(ll i=1;i<=n;i++)
//    {
//        for(ll j=0;j<=m;j++)
//        {
//            if(j==0)
//            {
//                dp[i][j]=max(dp[i-1][j],dp[i][j]);
//                dp[i][j]=max(dp[i-1][j+1],dp[i][j]);
//                continue;
//            }else if(j<m)
//            {
//                dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
//            }
//                //dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
//            if(n-i>m-j && dp[i-1][j-1]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
//        }
//    }
//    for(ll i=0;i<=n;i++)
//    {
//        for(ll j=0;j<=m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<dp[n][0];
//    //cout<<max(dp[n-1][0],dp[n-1][1]);
//}
//
