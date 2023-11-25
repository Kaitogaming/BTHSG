#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int MOD=1e6+7;
using namespace std;
ll dp[35][1000009];
    ll n,k;
ll solve(ll id,ll k)
{
    if(dp[id][k]!=-1) return dp[id][k];
    if(id<0) return 0;
    if(k==0) return dp[id][0]=1;
    if(id==0) return dp[0][k]=0;
    dp[id][k]=0;
    for(ll i=0;i<id && i<=k;i++)
    {
       dp[id][k]+=solve(id-1,k-i);
       dp[id][k]%=MOD;
    }
    return dp[id][k];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PERMUT.INP","r",stdin);
    freopen("PERMUT.OUT","w",stdout);
    cin>>n>>k;
    int total = n * (n - 1) / 2;
    if (k < 0 || k > total)
    {
        cout << 0;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,k);
}

