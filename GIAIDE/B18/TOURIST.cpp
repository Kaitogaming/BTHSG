#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
const int N=1e2+5;
using namespace std;
ll ng[N][N];
ll d[N];
bool check[N];
bool kt[N];
vector <pair<ll,ll> > adj[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOURIST.INP","r",stdin);
    freopen("TOURIST.OUT","w",stdout);
    memset(d,0x3f,sizeof(d));
    ll n,u,v;
    cin>>n>>u>>v;
    d[u]=INT_MIN;
        ll a,b,c;
    while(cin>>a>>b>>c)
    {
        adj[a].push_back(mp(b,-c));
        adj[b].push_back(mp(a,-c));
        //cout<<a<<" "<<b<<" "<<c<<endl;
    }
    priority_queue<pair<ll,ll> > q;

    q.push(mp(0,u));

    while(q.size())
    {
        pair<ll,ll> a=q.top();

        ll x=a.se;

        ll y=a.fi;

        check[x]=1;

        q.pop();
        for(ll i=0;i < adj[x].size();i++)
        {
            ll r=adj[x][i].se;
            ll l=adj[x][i].fi;

            if(check[l]) continue;
            ll k=max(d[x],r);

            if(k<d[l])
            {
                d[l]=k;
                q.push(mp(-k,l));
                ng[x][y]=k;
                ng[y][x]=k;
            }
        }
    }
    vector <ll> kq;
    cout<<-d[v]<<endl;
//    ll cur=v;
//    do
//    {
//        kt[cur]=1;
//        kq.push_back(cur);
//        for(ll i=0;i<adj[cur].size();i++)
//        {
//            ll x=adj[cur][i].first;
//            ll y=adj[cur][i].second;
//            if(kt[x]) continue;
//            if(d[x]<=d[cur] && ng[x][cur]<=d[cur])
//            {
//                cur=x;
//                break;
//            }
//        }
//    }while(cur!=u);
//    reverse(kq.begin(),kq.end());
//    for(ll i=0;i<kq.size();i++)
//    {
//        cout<<kq[i]<< " ";
//    }
//    for(ll i=1;i<=n;i++)
//    {
//        cout<<d[i]<< " ";
//    }
}
