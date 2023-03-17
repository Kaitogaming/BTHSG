#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e6+5;
using namespace std;
ll n,k,beg=0,ans=0;
ll a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CSDK.INP","r",stdin);
    freopen("CSDK.OUT","w",stdout);
    cin>>n>>k;
    a[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        a[i]%=k;
    }
    sort(a,a+n+1);
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<a[i]<<' ';
//    }
    ll i=beg;
    while(i<=n)
    {
        ll cs=lower_bound(a,a+n+1,beg+1)-a;
        ans+=(cs-i)*(cs-i-1)/2;
        beg=a[cs];
        i=cs;
    }
    cout<<ans;
}
