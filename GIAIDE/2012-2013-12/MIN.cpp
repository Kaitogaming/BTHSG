#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[105][105];
bool check[105][105];
bool chien=1;
ll cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MIN.INP","r",stdin);
    freopen("MIN.OUT","w",stdout);
    memset(a,0,sizeof(a));
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            char s;
            cin>>s;
            if(s=='*')
            {
                a[i+2][j+2]=1;
                chien=0;
                cnt++;
            }else check[i+2][j+2]=1;
        }
    }
    if(chien || cnt==n*n)
    {
        cout<<0;
        return 0;
    }
    for(ll i=2;i<=n+2;i++)
    {
        for(ll j=2;j<=n+2;j++)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(ll i=2;i<=n+2;i++)
    {
        for(ll j=2;j<=n+2;j++)
        {
            if(check[i][j]==0) continue;
            //cout<<endl;
            ll sum;
            sum=a[i+1][j+1];
            //cout<<sum<<" ";
            sum-=a[i-2][j+1];
            //cout<<sum<<" ";
            sum-=a[i+1][j-2];
            //cout<<sum<<" ";
            sum+=a[i-2][j-2];
            if(sum==0) continue;
            cout<<i-1<<" "<<j-1<<" ";
            cout<<sum<<endl;
        }
    }
//    cout<<endl;
//    for(ll i=0;i<=n+2;i++)
//    {
//        for(ll j=0;j<=n+2;j++)
//        {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
