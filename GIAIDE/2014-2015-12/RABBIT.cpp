#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
ll dis[1005][1005];
ll d[1005][1005];
bool check[1005][1005];
ll move1[4]={1,-1,0,0};
ll move2[4]={0,0,1,-1};
ll mxy,mxx;
bool kt(ll x,ll y)
{
    return x>0 && y>0 && x<=mxx && y<=mxy;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("RABBIT.INP","r",stdin);
    freopen("RABBIT.OUT","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    ll n;
    cin>>n;
    pair<ll,ll> f;
    cin>>f.fi>>f.se;
    mxx=f.fi;
    mxy=f.se;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        d[a][b]=1;
        mxx=max(mxx,a);
        mxy=max(mxy,b);
    }
    mxx++;
    mxy++;
    priority_queue< pair < ll,pair <ll,ll> > > q;
    q.push({d[1][1],{1,1}});
    dis[1][1]=d[1][1];
    while(q.size())
    {
        pair<ll,pair<ll,ll> > p=q.top();
        q.pop();
        check[p.se.fi][p.se.se]=1;
        for(ll i=0;i<4;i++)
        {
             ll x=p.se.fi;
             ll y=p.se.se;
             if(kt(x+move1[i],y+move2[i])==0) continue;
             if(dis[x+move1[i]][y+move2[i]]>dis[x][y]+d[x+move1[i]][y+move2[i]])
             {
                 dis[x+move1[i]][y+move2[i]]=dis[x][y]+d[x+move1[i]][y+move2[i]];
                 q.push({-dis[x+move1[i]][y+move2[i]],{x+move1[i],y+move2[i]}});
             }
        }
    }
    cout<<dis[f.fi][f.se];
}
