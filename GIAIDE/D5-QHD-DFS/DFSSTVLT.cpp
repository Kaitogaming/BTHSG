#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
vector <ll> adj[N];
ll pprev[N];
bool check[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSSTVLT.INP","r",stdin);
    freopen("DFSSTVLT.OUT","w",stdout);
    ll n,m,u,v;
    cin>>n>>m>>u>>v;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue <ll> q;
    q.push(u);
    while(!check[v] && q.size())
    {
        ll a=q.front();
        q.pop();
        check[a]=1;
        for(ll i=0;i<adj[a].size();i++)
        {
             if(pprev[a]==adj[a][i]) continue;
             if(check[adj[a][i]]) continue;
             q.push(adj[a][i]);
             pprev[adj[a][i]]=a;
        }
    }
    vector <ll> ans;
    ll cur=v;
    do
    {
        ans.push_back(cur);
        cur=pprev[cur];
    }while(cur!=u);
    //reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<u;
}
