#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e2+5;
using namespace std;
ll a[N][N];
ll kq=0;
bool checkR[N][N];
ll checkD[N][N];
ll n,m;
ll cnt;
vector <char> ans[N];
void solve()
{
    ll i=0,j=0;
    while(i<n && j<m)
    {
        cnt-=a[i][j];
        checkD[i][j]-=a[i][j];
        a[i][j]=0;
        checkR[i][j]=0;
        if(i==n-1&& j==m-1) break;
        if(j!=m-1 && (checkR[i][j+1] || checkD[i+1][j]==0))
        {
            j++;
            ans[kq].push_back('R');
        }
        else
        {
            i++;
            ans[kq].push_back('D');
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    memset(checkD,0,sizeof(checkD));
    memset(checkR,0,sizeof(checkR));
    cin>>n>>m;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin>>a[i][j];
            cnt+=a[i][j];
        }
    }
//    for(ll i=0; i<n; i++)
//    {
//        for(ll j=0; j<m; j++)
//        {
//            cout<<a[i][j]<<" ";
//            //cnt+=a[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    for(ll i=0;i<n;i++)
    {
        bool kt=0;
        for(ll j=m-1;j>=0;j--)
        {
            if(a[i][j]==1) kt=1;
            checkR[i][j]=kt;
        }
    }
    for(ll j=0; j<m; j++)
    {
        for(ll i=n-1; i>=0; i--)
        {
            checkD[i][j]=checkD[i+1][j]+a[i][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(checkR[i][j])
            {
                cout<<1<<" ";
            }else cout<<0<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cout<<checkD[i][j]<<" ";
        }
        cout<<endl;
    }
    while(cnt)
    {
        solve();
        kq++;
    }
    cout<<kq<<endl;
    for(ll i=0; i<kq; i++)
    {
        for(ll j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
