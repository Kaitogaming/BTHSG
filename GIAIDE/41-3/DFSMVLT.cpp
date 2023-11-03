#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool check[3005];
vector <ll> adj[3005];
vector <ll> curans;
vector <ll> finalans;
void dfs(ll x)
{
    check[x]=1;
    curans.push_back(x);
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
        if(curans.size()>finalans.size())
        {
            finalans=curans;
        }
        curans.clear();
    }
    cout<<finalans.size()<<endl;
    for(ll i=0;i<finalans.size();i++)
    {
        cout<<finalans[i]<<" ";
    }
}
