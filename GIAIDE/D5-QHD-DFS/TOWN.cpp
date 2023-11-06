#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second.first
#define th second.second.first
#define fo second.second.second
const int N=5e3+5;
using namespace std;
pair<ll,pair<ll,pair<ll,ll> > > a[N];
ll dp[N];
ll pprev[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOWN.INP","r",stdin);
    freopen("TOWN.OUT","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].fi>>a[i].se>>a[i].th;
        a[i].fo=i+1;
        if(a[i].th>a[i].fi)
        {
            swap(a[i].th,a[i].fi);
        }
        if(a[i].th>a[i].se)
        {
            swap(a[i].th,a[i].se);
        }
        if(a[i].fi>a[i].se)
        {
            swap(a[i].fi,a[i].se);
        }
    }
    sort(a,a+n);
    reverse(a,a+n);
//    for(ll i=0;i<n;i++)
//    {
//        cout<<a[i].fi<<" "<<a[i].se<<" "<<a[i].th<<" "<<a[i].fo<<endl;
//    }
    dp[0]=a[0].th;
    ll ans=0;
    ll kq=0;
    for(ll i=1;i<n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(a[i].se<=a[j].se)
            {
                dp[i]=max(dp[i],dp[j]+a[i].th);
                if(dp[i]>ans)
                {
                    ans=dp[i];
                    pprev[i]=j;
                }
            }
        }
    }
    cout<<ans<<endl;
    vector <ll> finalans;
    ll pre=0;
    for(ll i=n-1;i>=0;i--)
    {
         if(dp[i]==ans && a[i].se>=pre)
         {
             finalans.push_back(i);
             ans-=a[i].th;
             pre=a[i].se;
         }
    }
    cout<<finalans.size()<<endl;
    reverse(finalans.begin(),finalans.end());
    for(ll i=0;i<finalans.size();i++)
    {
        ll x=finalans[i];
        cout<<a[x].fo<<" "<<a[x].fi<<" "<<a[x].se<<" "<<a[x].th<<endl;
    }
}
