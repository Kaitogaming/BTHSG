#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e6+5;
using namespace std;
ll n,k,ans=0;
ll a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BRIDGE.INP","r",stdin);
    freopen("BRIDGE.OUT","w",stdout);
    cin>>n>>k;
    a[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    if(k==0)
    {
        cout<<0;
        return 0;
    }
    ll i=0,j=1;
    while(j<=n && i<n)
    {
        if(a[j]-a[i]==k)
        {
            ans++;
            i++;
        }else if(a[j]-a[i]<k)
        {
            j++;
        }else if(a[j]-a[i]>k)
        {
            i++;
        }
    }
    cout<<ans;
}
