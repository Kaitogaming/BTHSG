#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll move1[4]={0,0,-1,1};
ll move2[4]={1,-1,0,0};
ll a[205][205];
    ll n,m;
bool check(ll x,ll y)
{
    return x>=0 && y>=0 && x<n && y<m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("VUON.INP","r",stdin);
    freopen("VUON.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(a[i][j]==1)
            for(ll k=0;k<4;k++)
            {
                ll x=i+move1[k];
                ll y=j+move2[k];
                if(check(x,y)==0 || a[x][y]==1) continue;
                ans++;
                //cout<<a[x][y]<<" "<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans;
}
