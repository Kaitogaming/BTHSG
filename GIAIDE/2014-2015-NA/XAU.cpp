#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
const ll MOD=1e9+7;
const ll MOD2=1e9+9;
const ll MOD3=1e9+3;
const int base=311,base2=113,base3=37;
const int N=2e5+5;
using namespace std;
ll x;
ll n;
ll POW[N];
ll POW2[N];
ll hashs[N];
ll hashs2[N];
map<ll,ll> mp;
ll ans=0;
ll calc(ll l, ll r)
{
    return (hashs[r]-hashs[l-1]*POW[r-l+1]+MOD*MOD)%MOD;
}
ll calc2(ll l,ll r)
{
    return (hashs2[r]-hashs2[l-1]*POW2[r-l+1]+MOD2*MOD)%MOD2;
}
bool solve(ll z)
{
    mp.clear();
    for(ll i=1;i<=n-z+1;i++)
    {
        ll c=calc(i,i+z-1);
        mp[c]++;
    }
    map<ll,ll>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>=x)
        {
            return 1;
        }
    }
    return 0;
}
bool solve2(ll z)
{
    mp.clear();
    for(ll i=1;i<=n-z+1;i++)
    {
        mp[calc2(i,i+z-1)]++;
    }
    map<ll,ll>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>=x)
        {
             return 1;
        }
    }
    return 0;
}
//bool solve3(ll z)
//{
//    mp.clear();
//    for(ll i=1;i<=n-z+1;i++)
//    {
//        mp[calc3(i,i+z-1)]++;
//    }
//    map<ll,ll>::iterator it;
//    for(it=mp.begin();it!=mp.end();it++)
//    {
//        if(it->second>=2)
//        {
//             return 1;
//        }
//    }
//    return 0;
//
//}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XAU.INP","r",stdin);
    freopen("XAU.OUT","w",stdout);
    cin>>n;
    x=2;
    string s;
    cin>>s;
    s=" "+s;
    POW[0]=1;
    for(ll i=1;i<=n;i++) POW[i]=(POW[i-1]*base)%MOD;
    for(ll i=1;i<=n;i++) hashs[i]=(hashs[i-1]*base+s[i]-'a')%MOD;
    POW2[0]=1;
    for(ll i=1;i<=n;i++) POW2[i]=(POW2[i-1]*base2)%MOD2;
    for(ll i=1;i<=n;i++) hashs2[i]=(hashs2[i-1]*base2+s[i]-'a')%MOD2;
//    POW3[0]=1;
//    for(ll i=1;i<=n;i++) POW3[i]=(POW3[i-1]*base3)%MOD3;
//    for(ll i=1;i<=n;i++) hashs3[i]=(hashs3[i-1]*base3+s[i])%MOD3;
    ll l=0,r=n;
    while(l<r)
    {
        ll mid=(l+r+1)/2;
        if(solve(mid) && solve2(mid))
        {
            l=mid;
            ans=max(ans,mid);
            //cout<<mid<<endl;
        }else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}
