#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll cnt=0;
ll ans[200005];
ll num[200005];
ll low[200005];
vector <ll> adj[200005];
void dfs(ll u, ll pre)
{
    ll child=0;
    num[u]=low[u]=++cnt;
    for(ll i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(v==pre) continue;
        if(num[v]==0)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            //if(low[v]==num[v]) bridge++;
            if(u==pre)
            {
                if(child>1) ans[u]++;
            }else if(low[v]>=num[u]) ans[u]++;
        }else
        {
            low[u]=min(low[u],num[v]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CKN.INP","r",stdin);
    freopen("CKN.OUT","w",stdout);
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
        if(!num[i]) dfs(i,i);
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<1+ans[i]<<endl;
    }
}
