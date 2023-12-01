#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
vector <ll> kq;
vector <ll> adj[N];
ll t[N];
ll ans=0;
bool check[N];
void dfs(ll x)
{
     check[x]=1;
     ans+=t[x-1];
     kq.push_back(x);
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
    freopen("DFSTS.INP","r",stdin);
    freopen("DFSTS.OUT","w",stdout);
    ll n,m,s;
    cin>>n>>m>>s;
    for(ll i=0;i<n;i++)
    {
        cin>>t[i];
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
        if(check[i])continue;
        ans=0;
        kq.clear();
        dfs(i);
        if(ans<=s)
        {
            for(ll i=0;i<kq.size();i++)
            {
                cout<<kq[i]<<" ";
            }
            cout<<endl;
        }
    }
}
