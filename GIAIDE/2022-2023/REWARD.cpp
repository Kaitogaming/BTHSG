#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e5+5;
using namespace std;
ll n,k;
ll a[MAXN];
ll dp[MAXN][4];
ll solve(ll id,ll dem)
{
     if(id==n)
     {
         return 0;
     }
     if(dp[id][dem]!=-1) return dp[id][dem];
     ll ans=solve(id+1,0);
     if(dem<k)
     {
         ans=max(ans,solve(id+1,dem+1)+a[id]);
     }
     return dp[id][dem]=ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("REWARD.INP","r",stdin);
    freopen("REWARD.OUT","w",stdout);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    cout<<solve(0,0);
}
