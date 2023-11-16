#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[105];
ll b[105];
ll dp[105][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("MUAVE.INP","r",stdin);
//    freopen("MUAVE.OUT","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    ll n;
    cin>>n;
    dp[0][0]=0;
    dp[0][1]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n-1;i++)
    {
        cin>>b[i];
    }
    for(ll i=1;i<=n;i++)
    {
        dp[i][1]=dp[i-1][1]+a[i];
        dp[i][1]=min(dp[i-1][0]+a[i],dp[i][1]);
        if(i>1)
        dp[i][0]=dp[i-1][1]-a[i-1]+b[i-1];
    }
    ll ans=min(dp[n][1],dp[n][0]);
    cout<<ans<<endl;
    ll cur=n;
    vector <ll> kq;
    while(ans>0)
    {
         if(ans-a[cur]==dp[cur-1][1])
         {
             kq.push_back(cur);
             ans-=a[cur];
             cur-=1;
         }else if(ans-a[cur]==dp[cur-1][0])
         {
             kq.push_back(cur);
             ans-=a[cur];
             cur-=1;
         }else if(ans-b[cur-1]+a[cur-1])
         {
             ans-=b[cur-1];
             ans+=a[cur-1];
             cur--;
             //cout<<cur<<" c ";
         }
    }
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
//    }
    reverse(kq.begin(),kq.end());
    for(ll i=0;i<kq.size();i++)
    {
        cout<<kq[i]<<" ";
    }
}

