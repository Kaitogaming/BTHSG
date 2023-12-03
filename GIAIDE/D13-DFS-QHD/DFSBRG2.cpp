#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
ll p[N];
ll sz[N];
ll ans=0;
vector <ll> adj[N];
ll find(ll x)
{
    while(x!=p[x]) x=p[x]=p[p[x]];
    return x;
}
bool check(ll x,ll y)
{
    return find(x)==find(y);
}
void hop(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    p[y]=x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSBRG2.INP","r",stdin);
    freopen("DFSBRG2.OUT","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)
    {
        sz[i]=1;
        p[i]=i;
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        hop(a,b);
    }
    for(ll i=0;i<k;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(check(a,b)) continue;
        hop(a,b);
        ans++;
    }
    cout<<ans;
}
