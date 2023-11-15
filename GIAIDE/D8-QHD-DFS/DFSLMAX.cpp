#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
ll ans=0;
vector <ll> adj[N];
ll deep=1;
ll mxdeep=1;
bool check[N];
void dfs(ll x)
{
    mxdeep=max(mxdeep,deep);
    check[x]=1;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(check[adj[x][i]]) continue;
        deep++;
        dfs(adj[x][i]);
        deep--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("DFSLMAX.INP","r",stdin);
//    freopen("DFSLMAX.OUT","w",stdout);
    ll n,m,u;
    cin>>n>>m>>u;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(u);
    cout<<mxdeep;
}
