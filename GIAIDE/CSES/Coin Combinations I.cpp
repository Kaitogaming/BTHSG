#include <bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;
ll n,x,ans=0;
ll a[109];
//void solve(ll id,ll cursum)
//{
//    if(cursum==x)
//    {
//        ans++;
//        for(ll i=0;i<curkq.size();i++)
//        {
//            cout<<kq[i]<<' ';
//        }
//        cout<<endl;
//        return;
//    }
//    if(id==n)
//    {
//        return;
//    }
//    if(cursum>x)
//    {
//        return;
//    }
//    for(ll i=0;i<n;i++)
//    {
//        if(a[i]+cursum<=x)
//        {
//        curkq.push_back(a[i]);
//        solve(id+1,cursum+a[i]);
//        curkq.pop_back();
//        }
//        solve(id+1,cursum);
//    }
//}
//2 2 2 2 3
ll dp[1000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    dp[0]=1;
    for(ll i=1;i<a[0];i++)
    {
        dp[i]=0;
    }
    for(ll i=a[0];i<=x;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i-a[j]>=0 && dp[i-a[j]]>0)
            {
            dp[i]+=dp[i-a[j]];
            dp[i]%=MOD;
            }else if(i-a[j]<0) break;
        }
    }
//    for(ll i=0;i<=x;i++)
//    {
//        cout<<dp[i]<<' ';
//    }
    cout<<dp[x];
}
