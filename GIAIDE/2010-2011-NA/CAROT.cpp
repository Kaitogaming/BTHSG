#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define mp make_pair
const int N=1e2+5;
using namespace std;
    ll n,m;
    ll u,v;
    ll a[N][N];
    ll move1[4]={0,0,-1,1};
    ll move2[4]={1,-1,0,0};
    bool check[N][N];
    pair<ll,ll> pre[N][N];
    ll p[N*N];
    ll sz[N*N];
    ll mx=INT_MIN;
ll calc(ll x,ll y)
{
    return x*m+y;
}
ll find(ll x)
{
    while(x!=p[x]) x=p[x]=p[p[x]];
    return x;
}
bool kt(ll x,ll y)
{
    return find(x)==find(y);
}
void hop(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    p[y]=x;
    sz[x]+=sz[y];
}
bool range(ll x,ll y)
{
    return x>=0 && y>=0 && x<n && y<m && a[x][y]==1;
}
bool range1(ll x,ll y)
{
    return x>=0 && y>=0 && x<n && y<m && check[x][y]==1;
}
bool ans(ll x,ll y)
{
      //cout<<sz[find(calc(x,y))]<<" dcm "<<mx<<endl;
      return sz[find(calc(x,y))]==mx;
}
void print(ll x,ll y)
{
    //cout<<x<<" "<<y<<endl;
    vector <pair<ll,ll>> kq;
    while(x!=u || y!=v)
    {
        kq.push_back(mp(x,y));
        x=pre[x][y].fi;
        y=pre[x][y].se;
    }
    kq.push_back(mp(u,v));
    reverse(kq.begin(),kq.end());
    cout<<kq.size()-1<<endl;
    for(ll i=0;i<kq.size();i++)
    {
        cout<<kq[i].fi+1<<" "<<kq[i].se+1<<endl;
    }
    exit(0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAROT.INP","r",stdin);
    freopen("CAROT.OUT","w",stdout);
    cin>>n>>m>>u>>v;
    u--;
    v--;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
            p[calc(i,j)]=calc(i,j);
            sz[calc(i,j)]=1;
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(a[i][j]==0) continue;
            for(ll k=0;k<4;k++)
            {
                ll x=i+move1[k];
                ll y=j+move2[k];
                if(range(x,y)==0) continue;
                hop(calc(i,j),calc(x,y));
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
                mx=max(mx,sz[calc(i,j)]);
        }
    }
    //cout<<mx;
    memset(check,1,sizeof(check));
    queue<pair<ll,ll>> q;
    q.push(mp(u,v));
    if(ans(u,v))
    {
        cout<<0<<endl;
        //cout<<u+1<<" "<<v+1;
        return 0;
    }
    check[u][v]=0;
    while(q.size())
    {
        pair<ll,ll> x=q.front();
        q.pop();
        check[x.fi][x.se]=0;
        for(ll i=0;i<4;i++)
        {
            ll c=x.fi+move1[i];
            ll d=x.se+move2[i];
            if(range1(c,d)==0) continue;
            check[c][d]=0;
            pre[c][d]=mp(x.fi,x.se);
            if(ans(c,d)==1) print(c,d);
            q.push(mp(c,d));
            //cout<<c<<" "<<d<<endl;
        }
    }
}
//6 6 1 6
//0 0 0 0 1 1
//0 0 0 0 1 1
//0 0 0 0 1 1
//0 0 0 0 1 1
//0 0 0 0 1 1
//1 1 1 0 0 0
