#include <bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;
ll n,x,ans=0;
ll a[109];
ll dp[1000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    dp[0]=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=a[i];j<=x;j++)
        {
            if(dp[j-a[i]]!=0)
            {
                dp[j]+=dp[j-a[i]];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[x];
}
