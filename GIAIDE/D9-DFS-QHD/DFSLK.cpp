#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll deep=1;
bool check[3005];
ll d[3005];
ll pre[3005];
vector <ll> adj[3005];
void dfs(ll x)
{
    d[x]=deep;
    check[x]=1;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(check[adj[x][i]]) continue;
        pre[adj[x][i]]=x;
        deep++;
        dfs(adj[x][i]);
        deep--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSLK.INP","r",stdin);
    freopen("DFSLK.OUT","w",stdout);
    ll n,m,u,v;
    fill(d,d+n+1,INT_MIN);
    cin>>n>>m>>u>>v;
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
        if(d[i]!=v) continue;
//        cout<<d[i]<<" ";
//        cout<<i<<endl;
        ll tv=i;
        ll cur=i;
        //cout<<cur<<endl;
        while(cur!=u)
        {
            cout<<cur<<" ";
            cur=pre[cur];
        }
        cout<<u<<endl;
    }
}
