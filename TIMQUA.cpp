#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0,cs;
ll a[100][100];
ll dp[100][100];
vector <ll> kq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TIMQUA.INP","r",stdin);
    freopen("TIMQUA.OUT","w",stdout);
    cin>>m>>n;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<m;i++)
    {
        dp[i][0]=a[i][0];
    }
//    for(ll i=1;i<n;i++)
//    {
//        dp[0][i]=max(dp[0][i-1],dp[1][i-1])+a[0][i];
//        dp[m-1][i]=max(dp[m-1][i-1],dp[m-2][i-1])+a[m-1][i];
//    }
    for(ll j=1;j<n;j++)
    {
        for(ll i=0;i<m;i++)
        {
            if(i==0)
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j-1])+a[i][j];
                continue;
            }
            if(i==m-1)
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-1])+a[i][j];
                continue;
            }
            dp[i][j]=max(dp[i][j-1],max(dp[i-1][j-1],dp[i+1][j-1]))+a[i][j];
        }
    }
    for(ll i=0;i<m;i++)
    {
        if(dp[i][n-1]>ans)
        {
            ans=dp[i][n-1];
            cs=i;
        }
    }
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    kq.push_back(cs+1);
    ll i=cs,j=n-1;
    while(j>0)
    {
        if(dp[i][j]-a[i][j]==dp[i][j-1])
        {
            j--;
            kq.push_back(i+1);
            continue;
        }
        if(i==1)
        {
                i++;
                j--;
                kq.push_back(i+1);
                continue;
        }

        if(i==m-1)
        {
                i--;
                j--;
                kq.push_back(i+1);
                continue;
        }
        if(dp[i][j]-a[i][j]==dp[i-1][j-1])
        {
            i--;
            j--;
            kq.push_back(i+1);
        }else
        {
            i++;
            j--;
            kq.push_back(i+1);
        }

    }
    for(ll i=kq.size()-1;i>=0;i--)
    {
        cout<<kq[i]<<' ';
    }
}
