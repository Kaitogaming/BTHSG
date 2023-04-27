#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,x,i,j;
    ll c[105];
    ll dp[1000005];
    dp[0]=0;
    cin >> n >> x;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(i=1;i<x+1;i++)
    {
        dp[i]=10e9;
        for(j=0;j<n;j++)
        {
            if(i>=c[j])
            {
                dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    if(dp[x]==10000000000)
    {
        cout<<-1;
        return 0;
    }
    cout<<dp[x];

}
