#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll ans=INT_MAX;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("game.inp","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++)
    {
        ll b;
        ll cs;
        cin>>b;
        cs=lower_bound(a,a+n,-b)-a;
        //cout<<cs<<endl;
        if(cs==n)
        {
            cs--;
            ans=min(ans,abs(a[cs]+b));
        }else if(cs==0)
        {
            ans=min(ans,abs(a[cs]+b));
        }else
        {
            ans=min(ans,abs(a[cs]+b));
            cs--;
            ans=min(ans,abs(a[cs]+b));
        }
    }
    cout<<ans;
}
