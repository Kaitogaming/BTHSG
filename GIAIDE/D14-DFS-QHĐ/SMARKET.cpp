#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const ll N=505,M=1e5+5,MOD=131131;
using namespace std;
ll v[N];
ll w[N];
ll dp[M];
map<ll,ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("SMARKET.INP","r",stdin);
    //freopen("SMARKET.OUT","w",stdout);
   ll s,n;
   cin>>s>>n;
   for(ll i=1;i<=n;i++)
   {
       cin>>v[i]>>w[i];
   }
   dp[0]=1;
   ll mx=0;
   for(ll i=1;i<=n;i++)
   {
        for(ll j=min(mx,s);j>=0;j--)
        {
            for(ll k=1;k<=w[i];k++)
            {
                if(dp[j]==0) continue;
                if(j+v[i]*k>s) break;
                dp[j+v[i]*k]+=dp[j];
                dp[j+v[i]*k]%=MOD;
                mx=max(mx,j+v[i]*k);
            }
        }
   }
   cout<<dp[s];
}
