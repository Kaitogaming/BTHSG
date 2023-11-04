#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=2e3+5;
using namespace std;
    ll n,m;
    ll a[N][N];
    ll move1[4]={1,-1,0,0};
    ll move2[4]={0,0,-1,1};
bool check(ll x,ll y)
{
    return x>=0 && x<n && y>=0 && y<m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("KE.INP","r",stdin);
    freopen("KE.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
//    for(ll i=0;i<n;i++)
//    {
//        for(ll j=0;j<m;j++)
//        {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            for(ll k=0;k<4;k++)
            {
                ll x=i+move1[k];
                ll y=j+move2[k];
                if(!a[i][j]) continue;
                if(check(x,y)==0) continue;
                if(a[i][j]!=a[x][y])
                {
                    ans++;
                  //  cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                }
            }
        }
    }
    cout<<ans;
}
