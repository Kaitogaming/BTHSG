#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
const int N=1e5+5;
using namespace std;
    ll n;
    vector <pair<ll,ll> > ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        ans.push_back(mp(b,n-a+1));
        //cout<<b<<" "<<n-a+1<<endl;
    }
    sort(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
