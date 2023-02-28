#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans=0;
ll a[77][77];
bool check[77][77];
void solve(ll i,ll j,ll x,ll curans)
{
    if(i==n-1 && j==n-1)
    {
        ans=max(ans,curans);
        return;
    }
    if(a[i+1][j]<0 && a[i][j+1]<0 && x==k) return;
    if(j!=n-1 && check[i][j+1]!=1)
    {
        check[i][j+1]=1;
        if(a[i][j+1]<0)
        solve(i,j+1,x+1,curans+a[i][j+1]);
        if(a[i][j+1]>=0)
        solve(i,j+1,x,curans+a[i][j+1]);
        check[i][j+1]=0;
    }
    if(i!=n-1 && check[i+1][j]!=1)
    {
        check[i+1][j]=1;
        if(a[i+1][j]<0)
        solve(i+1,j,x+1,curans+a[i+1][j]);
        if(a[i+1][j]>=0)
        solve(i+1,j,x,curans+a[i+1][j]);
        check[i+1][j]=0;
    }
    if(j && check[i][j-1]!=1)
    {
        check[i][j-1]=1;
        if(a[i][j-1]<0)
        solve(i,j-1,x+1,curans+a[i][j-1]);
        if(a[i][j-1]>=0)
        solve(i,j-1,x,curans+a[i][j-1]);
        check[i][j-1]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    memset(check,0,sizeof(check));
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    solve(0,0,0+a[0][0]<0,a[0][0]);
    cout<<ans;
}
