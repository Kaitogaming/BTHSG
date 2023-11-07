#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
const int N=1e3+5;
using namespace std;
//8 8
//. # # # # # # #
//# . . c . . . #
//# . # # # # . #
//# . # f . # . #
//# . # . c # c #
//# c . # # . . #
//# . f . . f . #
//. # # # # # # .
ll n,m;
ll a[N][N];
bool check[N][N];
ll move1[4]={1,-1,0,0};
ll move2[4]={0,0,-1,1};
bool kt(ll x,ll y)
{
    return x>=0 && x<n && y>=0 && y<m && check[x][y]==0 && a[x][y]<2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    ll chicken=0,fox=0;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            char s;
            cin>>s;
            if(s=='#')
            {
                a[i][j]=2;
                check[i][j]=1;
            }else if(s=='c')
            {
                a[i][j]=1;
                chicken++;
            }else if(s=='f')
            {
                a[i][j]=-1;
                fox++;
            }
        }
    }
    //cout<<fox<<" "<<chicken<<endl;
    queue<pair<ll,ll> > q;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(kt(i,j)==0) continue;
            q.push(mp(i,j));
            ll sum=0;
            ll curc=0;
            ll curf=0;
            while(q.size())
            {
                pair<ll,ll> b=q.front();
                q.pop();
                if(kt(b.fi,b.se)==0) continue;
                check[b.fi][b.se]=1;
                sum+=a[b.fi][b.se];
                if(a[b.fi][b.se]==1)
                {
                    curc++;
                    //cout<<b.fi<<" "<<b.se<<" ga"endl;
                }else if(a[b.fi][b.se]==-1)
                {
                    curf++;
                    //cout<<b.fi<<" "<<b.se<<" cao"endl;
                }
                for(ll k=0;k<4;k++)
                {
                    ll x=b.fi+move1[k];
                    ll y=b.se+move2[k];
                    if(kt(x,y)==0) continue;
                    q.push(mp(x,y));
                }
            }

            if(sum>0)
            {
                fox-=curf;
                //cout<<fox<<" "<<chicken<<" "<<i<<" "<<j<<" "<<sum<<endl;

            }else
            {
                chicken-=curc;
            //cout<<fox<<" "<<chicken<<" "<<i<<" "<<j<<" "<<sum<<endl;
            }
        }
    }
    cout<<fox<<" "<<chicken;
}
