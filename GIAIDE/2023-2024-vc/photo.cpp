#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll a[N];
ll b[N];
ll c[N];
ll cnt[4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("photo.inp","r",stdin);
    freopen("photo.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
        a[i]=cnt[1];
        b[i]=cnt[2];
        c[i]=cnt[3];
    }
    for(ll i=1;i<=m;i++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<" "<<b[r]-b[l-1]<<" "<<c[r]-c[l-1]<<endl;
    }
}
