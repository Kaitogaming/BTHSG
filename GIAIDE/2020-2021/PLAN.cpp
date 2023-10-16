#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi second.first
#define se second.second
const int N=1e3+5;
using namespace std;
char a[N][N];
ll n,m;
bool check[N][N];
ll move1[4]={-1,1,0,0};
ll move2[4]={0,0,-1,1};
bool kt(ll x,ll y)
{
    return(x>=0 && x<n && y>=0 && y<m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PLAN.INP","r",stdin);
    freopen("PLAN.OUT","w",stdout);
    queue<pair<char,pair<ll,ll>>> q;
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
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
    ll ans=0;
    ll mxans=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(check[i][j])continue;
            check[i][j]=1;
            q.push({a[i][j],{i,j}});
            ll cnt=1;
            while(q.size())
            {
                auto z=q.front();
                for(ll i=0;i<4;i++)
                {
                    ll o=z.fi+move1[i];
                    ll p=z.se+move2[i];
                    if(kt(o,p) && a[o][p]==z.first && check[o][p]==0)
                    {
                        q.push({a[o][p],{o,p}});
                        check[o][p]=1;
                        cnt++;
                    }
                }
                q.pop();
            }
            mxans=max(mxans,cnt);
            ans++;
        }
    }
    cout<<ans<<endl<<mxans;
}
