#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
using namespace std;
vector <ll> adj[505];
bool check[505];
ll pprev[505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FLOWERS.INP","r",stdin);
    freopen("FLOWERS.OUT","w",stdout);
    ll n,m,x;
    cin>>n>>m>>x;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<ll,ll> > q;
    q.push(mp(1,0));
    pprev[1]=1;
    while(q.size())
    {
         pair<ll,ll> a=q.front();
         if(a.fi==n)
         {
             cout<<x-a.se+1<<endl;
             break;
         }
         q.pop();
         for(ll i=0;i<adj[a.first].size();i++)
         {
             if(pprev[adj[a.fi][i]]!=0) continue;
              pprev[adj[a.fi][i]]=a.fi;
              q.push(mp(adj[a.fi][i],a.se+1));
         }
    }
    ll cur=n;
    vector <ll> ans;
    while(cur!=1)
    {
        ans.push_back(cur);
        cur=pprev[cur];
    }
    cout<<1;
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<" "<<ans[i];
    }
}
