#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool kt[3005];
vector <ll> adj[3005];
bool check[3005];
ll pre[3005];
void dfs(ll x)
{
    check[x]=1;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(check[adj[x][i]]) continue;
        pre[adj[x][i]]=x;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSSECUR.INP","r",stdin);
    freopen("DFSSECUR.OUT","w",stdout);
    ll n,m,u,k;
    cin>>n>>m>>u>>k;
    for(ll i=0;i<k;i++)
    {
        ll a;
        cin>>a;
        kt[a]=1;
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(kt[a] || kt[b]) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(u);
    for(ll i=1;i<=n;i++)
    {
        if(i==u || check[i]==0) continue;
        ll cur=i;
        while(cur!=u)
        {
            cout<<cur<<" ";
            cur=pre[cur];
        }
        cout<<u<<endl;
    }
}
