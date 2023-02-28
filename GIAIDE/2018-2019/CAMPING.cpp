#include <bits/stdc++.h>
#define ll long long
const int MaxN=1e5;
using namespace std;
ll a[MaxN];
int main()
{
    freopen("CAMPING.INP","r",stdin);
    freopen("CAMPING.OUT","w",stdout);
    ll l,n,ans,maxdt=0;
    cin>>l>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ans=max(a[0],l-a[n-1]);
    for(ll i=1; i<n; i++)
    {
        maxdt=max(a[i]-a[i-1],maxdt);
    }
    maxdt/=2;
    ans=max(maxdt,ans);
    cout<<ans;
}
