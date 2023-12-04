#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
vector<ll> adj[3005];
vector <ll> curans;
ll n,m,u,v;
    bool kt[3005];
    bool check=1;
void dfs1(ll x,ll pre)
{
    kt[x]=1;
     for(ll i=0;i<adj[x].size();i++)
     {
         if(adj[x][i]==pre) continue;
         if(kt[adj[x][i]]) continue;
         kt[adj[x][i]]=1;
         curans.push_back(adj[x][i]);
         if(adj[x][i]==v)
         {
             for(ll i=0;i<curans.size();i++)
             {
                 cout<<curans[i]<<" ";
             }
             cout<<endl;
             check=0;
         }
         dfs1(adj[x][i],x);
         curans.pop_back();
         kt[adj[x][i]]=0;
     }
     kt[x]=0;
}
void dfs2(ll x,ll pre)
{
    kt[x]=1;
     for(ll i=0;i<adj[x].size();i++)
     {
         if(adj[x][i]==pre) continue;
         if(kt[adj[x][i]]) continue;
         kt[adj[x][i]]=1;
         curans.push_back(adj[x][i]);
         if(adj[x][i]==u)
         {
             for(ll i=0;i<curans.size();i++)
             {
                 cout<<curans[i]<<" ";
             }
             cout<<endl;
             check=0;
         }
         dfs2(adj[x][i],x);
         curans.pop_back();
         kt[adj[x][i]]=0;
     }
    kt[x]=0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSOST.INP","r",stdin);
    freopen("DFSOST.OUT","w",stdout);
    cin>>n>>m>>u>>v;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    curans.push_back(u);
    dfs1(u,u);
    curans.clear();
    curans.push_back(v);
    dfs2(v,v);
    if(check)
    {
        cout<<-1;
    }
}
