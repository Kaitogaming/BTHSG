#include <bits/stdc++.h>
#define ll long long
#define endl "n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("REPORT.INP","r",stdin);
    freopen("REPORT.OUT","w",stdout);
    ll n;
    cin>>n;
    ll ans=INT_MAX;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(a>0)
        {
            ans=min(ans,a);
        }else
        {
            sum+=a;
        }
    }
    if(sum<0)
    {
        cout<<sum;
        return 0;
    }else
    {
        cout<<ans;
        return 0;
    }
}
