#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
vector <ll> adj[5005];
bool check[5005];
ll pprev[5005];
void dfs(ll x)
{
    check[x]=1;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==pprev[x] || check[adj[x][i]]) continue;
        pprev[adj[x][i]]=x;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DANCU.INP","r",stdin);
    freopen("DANCU.OUT","w",stdout);
    ll m,n;
    ll dem=0;
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
        dem++;
    }
    cout<<dem;
}
