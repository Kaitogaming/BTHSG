#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
const int N=1e5+5;
using namespace std;
ll d[N];
bool check[N];
vector<pair<ll,ll> > adj[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("VANCHUYEN.INP","r",stdin);
    freopen("VANCHUYEN.OUT","w",stdout);
    ll n,m,u,v;
    cin>>n>>m>>u>>v;
    //memset(d,0x3f,sizeof(d));
    for(ll i=1;i<=n;i++) d[i]=LLONG_MIN;
    d[u]=0;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(mp(b,-c));
        //adj[b].push_back(mp(a,-c));
    }
    priority_queue<pair<ll,ll> > q;
    q.push(mp(0,u));
    while(q.size())
    {
        pair<ll,ll> x=q.top();
        q.pop();
        if(check[x.se]) continue;
        check[x.se]=1;
        for(ll i=0;i<adj[x.se].size();i++)
        {
            if(check[adj[x.se][i].fi]) continue;
            ll l=adj[x.se][i].fi;
            ll r=adj[x.se][i].se;
            if(d[l]<d[x.se]+r)
            {
                d[l]=d[x.se]+r;
                q.push(mp(d[l],l));
            }
        }
    }
//    for(ll i=1;i<=n;i++)
//    {
//        cout<<-d[i]<<" ";
//    }
    cout<<-d[v];
}
