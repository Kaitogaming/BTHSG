#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi second.first
#define se second.second
const int N=1e3+5;
using namespace std;
ll n,m;
pair<ll,pair<ll,ll>> ans[N];
bool compare(pair<ll,pair<ll,ll>> x,pair<ll,pair<ll,ll>> y)
{
    return(x.first>y.first);
}
int main()
{
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        ans[i].se=i+1;
        ans[i].first=0;
        ans[i].fi=0;
        for(ll j=0;j<m;j++)
        {
            ll a;
            cin>>a;
            ans[i].first++;
            if(a==0)
            {
                ans[i].first--;
            }
            ans[i].fi+=a;
        }
    }
    sort(ans,ans+n,compare);
//    for(ll i=0;i<n;i++)
//    {
//        cout<<ans[i].first<<" "<<ans[i].fi<<" "<<ans[i].se<<endl;
//    }
    ll x;
    x=ans[0].first;
    ll kq=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        if(ans[i].first!=x) break;
        kq=min(kq,ans[i].fi);
    }
    vector<ll> flans;
    for(ll i=0;i<n;i++)
    {
        if(ans[i].first!=x) break;
        if(ans[i].fi==kq) flans.push_back(ans[i].se);
    }
    sort(flans.begin(),flans.end());
    for(ll i=0;i<flans.size();i++)
    {
        cout<<flans[i]<<" ";
    }
}
