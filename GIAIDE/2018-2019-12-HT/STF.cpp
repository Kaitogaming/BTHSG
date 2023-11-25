#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("STF.INP","r",stdin);
    freopen("STF.OUT","w",stdout);
    ll n;
    cin>>n;
    map <ll,ll> chan;
    map <ll,ll> le;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(a%2)
        {
            le[a]++;
        }else
        {
            chan[a]++;
        }
    }
    map<ll,ll>::iterator it;
    for(it=chan.begin();it!=chan.end();it++)
    {
        for(ll i=0;i<it->second;i++)
        {
            cout<<it->first<<" ";
        }
    }
    vector <ll> ans;
    for(it=le.begin();it!=le.end();it++)
    {
        for(ll i=0;i<it->second;i++)
        {
            ans.push_back(it->first);
        }
    }
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
