#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
vector <ll> adj[105];
ll pre[105];
    ll u,v;
void dfs(ll x)
{
    if(x==v)
    {
        ll cur=x;
        vector <ll> ans;
        while(cur!=u)
        {
            ans.push_back(cur);
            cur=pre[cur];
        }
        ans.push_back(u);
        reverse(ans.begin(),ans.end());
        for(ll i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        exit(0);
    }
    for(ll i=0;i<adj[x].size();i++)
    {
        if(pre[adj[x][i]]!=0) continue;
        pre[adj[x][i]]=x;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XEBUYT.INP","r",stdin);
    freopen("XEBUYT.OUT","w",stdout);
    ll n;
    cin>>n;
    cin>>u>>v;
    ll a,b;
    while(cin>>a>>b)
    {
        cout<<a<<" "<<b<<endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pre[u]=u;
    dfs(u);
    cout<<-1;
}
