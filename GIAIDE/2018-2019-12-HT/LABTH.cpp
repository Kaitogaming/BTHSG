#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
const int N=1e3+5;
using namespace std;
pair<ll,ll> start;
ll move1[4]={0,0,-1,1};
ll move2[4]={1,-1,0,0};
char move3[4]={'E','W','N','S'};
char pre[N][N];
ll a[N][N];
ll n,m;
bool check(ll x,ll y)
{
    return x>=0 && y>=0 && x<n && y<m && a[x][y]==1;
}
bool stop(ll x,ll y)
{
    return x==0 || y==0 || x==n-1 || y==m-1;
}
void solve(ll x,ll y)
{
     vector <char> kq;
     while(x!=start.fi || y!=start.se)
     {
         //cout<<x<<" "<<y<<endl;
         kq.push_back(pre[x][y]);
         for(ll i=0;i<4;i++)
         {
             if(pre[x][y]==move3[i])
             {
                 x-=move1[i];
                 y-=move2[i];
                 break;
                 //cout<<x<<" "<<y<<"DC"<<endl;
             }
         }
     }
     reverse(kq.begin(),kq.end());
     for(ll i=0;i<kq.size();i++)
     {
         cout<<kq[i];
     }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("LABTH.INP","r",stdin);
    freopen("LABTH.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            char s;
            cin>>s;
            if(s=='.')
            {
                a[i][j]=1;
            }else if(s=='*')
            {
                a[i][j]=1;
                start=make_pair(i,j);
            }
        }
    }
    queue<pair<ll,ll>> q;
    q.push(start);
    while(q.size())
    {
        pair<ll,ll> b=q.front();
        a[b.fi][b.se]=0;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll x=b.fi+move1[i];
            ll y=b.se+move2[i];
            if(check(x,y)==0) continue;
            a[x][y]=0;
            pre[x][y]=move3[i];
            if(stop(x,y))
            {
                //cout<<x<<" "<<y<<endl;
                solve(x,y);
            }
            q.push(make_pair(x,y));
        }
    }
//    cout<<endl;
//    for(ll i=0;i<n;i++)
//    {
//        for(ll j=0;j<m;j++)
//        {
//            if(pre[i][j]==0)
//            {
//                cout<<"# ";
//            }else
//            cout<<pre[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
