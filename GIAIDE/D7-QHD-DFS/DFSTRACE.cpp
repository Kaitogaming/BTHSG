#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
vector <ll> adj[3005];
ll pprev[3005];
void dfs(ll x)
{
    for(ll i=0;i<adj[x].size();i++)
    {
        if(pprev[x]==adj[x][i]) continue;
        pprev[adj[x][i]]=x;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSTRACE.INP","r",stdin);
    freopen("DFSTRACE.OUT","w",stdout);
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
    for(ll i=1;i<=n;i++)
    {
        if(pprev[i]==0) continue;
        ll cur=i;
        while(cur!=u)
        {
            cout<<cur<<" ";
            cur=pprev[cur];
        }
        cout<<cur<<endl;
    }
}
