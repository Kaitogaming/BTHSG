#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
ll pre[N];
vector <ll> adj[N];
void dfs(ll x)
{
    for(ll i=0;i<adj[x].size();i++)
    {
        if(pre[adj[x][i]]) continue;
        pre[adj[x][i]]=x;
        dfs(adj[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSORIEN.INP","r",stdin);
    //freopen("DFSORIEN.OUT","w",stdout);
    ll n,m,s;
    cin>>n>>m>>s;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(s);
    bool check=1;
    for(ll i=1;i<=n;i++)
    {
        if(i==s) continue;
        if(pre[i]==0) continue;
        check=0;
        ll cur=i;
        while(cur!=s)
        {
             cout<<cur<<" ";
             cur=pre[cur];
        }
        cout<<cur<<endl;
    }
    if(check)
    {
        cout<<-1;
    }
}
