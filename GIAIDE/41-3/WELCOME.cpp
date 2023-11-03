#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi second.first
#define se second.second
#define mp make_pair
using namespace std;
vector< pair<ll,pair<ll,ll>>> a;
ll dp[205];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("WELCOME.INP","r",stdin);
    freopen("WELCOME.OUT","w",stdout);
    memset(dp,INT_MIN,sizeof(dp));
    ll n;
    cin>>n;
    dp[0]=0;
    a.push_back(mp(0,mp(0,0)));
    for(ll i=0;i<n;i++)
    {
        ll c,d,e;
        cin>>c>>d>>e;
        a.push_back(mp(c,mp(d,e)));
    }
    sort(a.begin(),a.end());
//    for(ll i=0;i<a.size();i++)
//    {
//        cout<<a[i].first<<" "<<a[i].fi<<" "<<a[i].se<<endl;
//    }
    ll ans=INT_MIN;
    for(ll i=1;i<a.size();i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(a[i].first-a[j].first<abs(a[i].fi-a[j].fi)) continue;
            dp[i]=max(dp[i],dp[j]+a[i].se);
            ans=max(ans,dp[i]);
        }
    }
//    for(ll)
    cout<<ans;
}
