#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
vector <ll> adj[N];
ll d[N];
ll deep=1;
ll pprev[N];
ll up[N][30];
void dfs(ll x)
{
   d[x]=deep;
   for(ll i=0;i<adj[x].size();i++)
   {
        if(pprev[x]==adj[x][i]) continue;
        pprev[adj[x][i]]=x;
        up[adj[x][i]][0]=x;
        deep++;
        dfs(adj[x][i]);
   }
   deep--;
}
ll lca(ll a,ll b)
{
    if(d[a]>d[b]) swap(a,b);
    ll k=d[b]-d[a];
    for(ll i=0;i<=25;i++)
    {
        if(k&1<<i)
        {
            b=up[b][i];
        }
    }
    if(b==a) return a;
    for(ll i=19;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
ll dis(ll x,ll y)
{
    ll k=lca(x,y);
      return d[x]+d[y]-2*d[k];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    up[1][0]=1;
    dfs(1);
    for(ll j=1;j<20;j++)
    {
        for(ll i=1;i<=n;i++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    ll x,y;
    ll mxdis=INT_MIN;
    for(ll i=2;i<=n;i++)
    {
         if(mxdis<dis(1,i))
         {
             mxdis=dis(1,i);
             x=i;
         }
    }
    mxdis=INT_MIN;
    for(ll i=1;i<=n;i++)
    {
        if(mxdis<dis(x,i))
        {
            mxdis=dis(x,i);
            y=i;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<max(dis(i,x),dis(i,y))<<endl;
    }
}
