#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
using namespace std;
ll p[N];
ll sz[N];
ll find(ll x)
{
    while(x!=p[x])
    {
        x=p[x]=p[p[x]];
    }
    return x;
}
void hop(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(sz[x]<sz[y]) swap(x,y);
    p[y]=x;
    sz[x]+=sz[y];

}
bool check(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("HAM.INP","r",stdin);
    freopen("HAM.OUT","w",stdout);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        sz[i]=1;
    }
    ll a,b;
    while(cin>>a,cin>>b)
    {
        hop(a,b);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(check(i,j)) continue;
            ans++;
            hop(i,j);
        }
    }
    cout<<ans;

}
