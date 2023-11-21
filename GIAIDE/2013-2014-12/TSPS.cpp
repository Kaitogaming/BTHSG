#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[105][105];
ll p[10005];
ll sz[10005];
ll move1[4]={0,0,-1,1};
ll move2[4]={1,-1,0,0};
    ll n,m;
ll find(ll x)
{
    while(x!=p[x])
    {
        x=p[x];
    }
    return x;
}
void hop(ll x, ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    p[y]=x;
    sz[x]+=sz[y];
}
bool check(ll x,ll y)
{
    return find(x)==find(y);
}
bool kt(ll x,ll y)
{
    return x>=0 && y>=0 && x<n && y<m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TSPS.INP","r",stdin);
    freopen("TSPS.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            char s;
            cin>>s;
            if(s=='A')
            {
                a[i][j]=1;
            }
            sz[i*m+j]=1;
            p[i*m+j]=i*m+j;
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            for(ll k=0;k<4;k++)
            {
                ll x=i+move1[k];
                ll y=j+move2[k];
                if(kt(x,y)==0) continue;
                if(a[i][j]!=a[x][y]) continue;
                if(check(i*m+j,x*m+y)) continue;
                //cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                hop(i*m+j,x*m+y);
            }
        }
    }
    ll x,y,z,c;
    while(cin>>x>>y>>z>>c)
    {
        x--;
        y--;
        z--;
        c--;
        if(check(x*m+y,z*m+c))
        {
            cout<<1<<endl;
        }else
        {
            //cout<<find(x*m+y)<<" "<<find(z*m+c)<<endl;
            //cout<<a[x][y]<<" "<<a[z][c]<<endl;
            cout<<0<<endl;
        }
    }
}
