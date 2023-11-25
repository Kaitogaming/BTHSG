#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
ll dp[N][N];
ll w[N];
ll v[N];
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("KSACK.INP","r",stdin);
    freopen("KSACK.OUT","w",stdout);
    ll n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j<w[i]) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
//    for(ll i=0;i<=n;i++)
//    {
//        for(ll j=0;j<=m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<dp[n][m]<<endl;
    vector <ll> ans;
    while(n>0)
    {
        if(dp[n][m]==dp[n-1][m])
        {
            n--;
        }else
        {
            ans.push_back(n);
            m-=w[n];
            n--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
