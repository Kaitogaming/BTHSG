#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
ll v[N];
bool check[N];
vector<ll> adj[N];
vector<ll> curans;
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
    freopen("DFSTK.INP","r",stdin);
    freopen("DFSTK.OUT","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
        //cout<<v[i]<<" ";
    }
    //cout<<endl;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <ll> ans;
    for(ll i=1;i<=n;i++)
    {
        if(check[i]) continue;
        curans.clear();
        dfs(i);
        if(curans.size()>ans.size())
        {
            ans=curans;
        }
    }
    cout<<ans.size()<<" ";
    ll sum=0,mx=INT_MIN;
    for(ll i=0;i<ans.size();i++)
    {
        sum+=v[ans[i]];
        mx=max(mx,v[ans[i]]);
    }
    cout<<sum-mx;
}
