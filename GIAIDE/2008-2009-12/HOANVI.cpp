#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e5+5;
using namespace std;
pair <ll,ll> a[N];
vector < pair <ll, pair<ll,ll> > >ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    ll mn=INT_MAX;
    ll mx=0;
    for(ll i=1;i<=n;i++)
    {
       mn=min(mn,a[i].second);
       mx=max(mx,a[i].second);
       //cout<<mx<<" "<<mn<<" "<<a[i].first<<" "<<a[i].second<<endl;
       if(mx-mn==a[i].first-1)
       {
           ans.push_back(make_pair(mn,make_pair(mx,a[i].first)));
       }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }
}
