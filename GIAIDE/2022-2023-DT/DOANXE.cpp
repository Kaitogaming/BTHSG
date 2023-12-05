#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
using namespace std;
double t[N];
double v[N];
ll w[N];
double dp[N];
    ll x=1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DOANXE.INP","r",stdin);
    freopen("DOANXE.OUT","w",stdout);
    ll n,m,l;
    cin>>n>>m>>l;
    for(ll i=0;i<=n;i++) dp[i]=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        w[i]+=w[i-1];
        t[i]=l/v[i];
    }
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<t[i]<<" ";
//    }
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        double check=INT_MIN;
        for(ll j=i;j>0;j--)
        {
            check=max(check,t[j]);
            ll cur=w[i]-w[j-1];
            if(cur>m) break;
            dp[i]=min(dp[i],dp[j-1]+check);
            //cout<<j-1<<" "<<i<<" "<<get(j-1,i)<<" ";
        }
    }
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<dp[i]<<" ";
//    }
    cout<<fixed<<setprecision(2)<<dp[n];
}
