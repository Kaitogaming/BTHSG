#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000][2000];
ll dp[2000][2000];
ll kq[2000];
ll n,m,i,j,ans,cs;
int main()
{
    freopen("RACE.INP","r",stdin);
    freopen("RACE.OUT","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(j=0;j<m;j++)
    {
        dp[0][j]=a[0][j];
    }
    for(i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i][0];
        dp[i][m-1]=min(dp[i-1][m-2],dp[i-1][m-1])+a[i][m-1];
        for(j=1;j<m-1;j++)
        {
            dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+a[i][j];
        }
    }
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<m;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    ans=dp[n-1][0];
    for(j=1;j<m;j++)
    {
        if(dp[n-1][j]<ans)
        {
            ans=dp[n-1][j];
            cs=j;
            kq[n-1]=a[n-1][j];
        }
    }
    cout<<ans<<endl;
    for(i=n-2;i>=0;i--)
    {
        if(cs>0)
        {
         j=cs-1;
        }else {j=cs;}
        while(dp[i+1][cs]-a[i+1][cs]!=dp[i][j])
        {
            j++;
        }
        cs=j;
        kq[i]=a[i][cs];
    }
    for(i=0;i<n;i++)
    {
        cout<<kq[i]<<' ';
    }
}
//6 5 1 3
//7 9 8 9
//16 11 14 12
