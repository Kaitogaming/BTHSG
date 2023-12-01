#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e3+5;
using namespace std;
vector <ll> adj[N];
ll snt[50000005];
ll ans=0,finalans=0;
bool check[N];
void dfs(ll x)
{
     check[x]=1;
     ans+=x;
     for(ll i=0;i<adj[x].size();i++)
     {
         if(check[adj[x][i]]) continue;
         dfs(adj[x][i]);
     }
}
void first()
{
    memset(snt,1,sizeof(snt));
    snt[0]=0;
    snt[1]=0;
    for(ll i=2;i<=4600000;i++)
    {
        if(snt[i])
        for(ll j=i+i;j<=4600000;j+=i)
        {
            snt[j]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DFSTS.INP","r",stdin);
    freopen("DFSTS.OUT","w",stdout);
    first();
    ll n,m,s;
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
        if(check[i])continue;
        ans=0;
        dfs(i);
        if(snt[ans] && ans>finalans)
        {
             finalans=ans;
        }
    }
    cout<<finalans;
}
