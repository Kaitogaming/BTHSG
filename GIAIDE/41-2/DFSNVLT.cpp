#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool check[3005];
vector <ll> adj[3005];
void dfs(ll x)
{
    check[x]=1;
    cout<<x<<" ";
    for(ll i=0;i<adj[x].size();i++)
    {
        if(check[adj[x][i]]) continue;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSNVLT.INP","r",stdin);
    freopen("DFSNVLT.OUT","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
        if(check[i]) continue;
        dfs(i);
        cout<<endl;
    }
}
