#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e4+5;
ll a[N];
ll dp[N];
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("RAND.INP","r",stdin);
    ll n,p;
    memset(dp,0x3f,sizeof(dp));
    cin>>n>>p;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            dp[i]=min(dp[i],dp[j]+(a[i]-a[j]-p)*(a[i]-a[j]-p));
        }
    }
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<dp[i]<<" ";
//    }
    cout<<dp[n]<<endl;
    ll cur=n;
    vector <ll> ans;
    while(cur!=0)
    {
        ans.push_back(cur);
        ll check=cur-1;
        for(;check>=0;check--)
        {
            ll sum=a[cur]-a[check]-p;
            sum*=sum;
            //cout<<sum<<" "<<cur<<" "<<check<<" "<<dp[cur]<<" "<<dp[check]<<endl;
             if(dp[cur]-sum==dp[check])
             {
                 cur=check;
                 break;
             }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
