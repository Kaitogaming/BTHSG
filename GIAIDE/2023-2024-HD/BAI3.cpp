#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+5;
using namespace std;
ll ans=INT_MAX;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>k)
        {
            ans=min(ans,a[i]);
        }
        a[i]+=a[i-1];
    }
    ll kq=LLONG_MIN;
    for(ll i=k;i<=n;i++)
    {
       kq=max(kq,a[i]-a[i-k]);
    }
    cout<<ans<<endl;
    cout<<kq;
}
