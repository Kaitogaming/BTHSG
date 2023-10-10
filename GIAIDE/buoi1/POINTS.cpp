#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
const int N=1e3+5;
using namespace std;
    ll n,d;
pair<ll,ll> a[N];
bool check[N];
double dis(ll x,ll y,ll a,ll b)
{
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
void solve(ll x,ll y)
{
    for(ll i=0;i<n;i++)
    {
        if(check[i]) continue;
        if(dis(x,y,a[i].fi,a[i].se)>d)
        {
            check[i]=1;
            //cout<<dis(x,y,a[i].fi,a[i].se)<<" "<<x<<" "<<y<<" "<<a[i].fi<<" "<<a[i].se<<endl;
            solve(a[i].fi,a[i].se);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("POINTS.INP","r",stdin);
//    freopen("POINTS.OUT","w",stdout);
    ll ans=0;
    cin>>n>>d;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    //sort(a,a+n);
    for(ll i=0;i<n;i++)
    {
        if(check[i]) continue;
        check[i]=1;
        ans++;
        solve(a[i].fi,a[i].se);
    }
    cout<<ans;
}
