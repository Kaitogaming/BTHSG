#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=505,M=1e6+5,MOD=131131;
using namespace std;
ll dp[M];
ll v[N];
ll w[N];
map<ll,ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SMARKET.INP","r",stdin);
    //freopen("SMARKET.OUT","w",stdout);
    ll n,m;
    cin>>m>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>v[i]>>w[i];
    }
    ll mx=0;
    mp[0]=1;
    for(ll i=1;i<=n;i++)
    {
        map<ll,ll>::iterator it=mp.end();
        it--;
        if(it==mp)
        for(;it!=mp.begin();it--)
        {
            for(ll j=1;j<=w[i];j++)
            {
                ll sum=v[i]*j;
                mp[it->first+sum]%=MOD;                mp[it->first+sum]+=it->second;
                mp[it->first+sum]%=MOD;
            }
        }
        for(ll j=1;j<=w[i];j++)
        {
            mp[v[i]*j]++;
            mp[v[i]*j]%=MOD;
        }
    }
    map<ll,ll>::iterator it;
//    for(it=mp.begin();it!=mp.end();it++)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
    cout<<mp[m];
}
