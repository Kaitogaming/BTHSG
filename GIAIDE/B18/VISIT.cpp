#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
const int N=2e4+5;
using namespace std;
pair<ll,ll> dp[N][2];
ll cal(ll cur,ll ed,ll beg)
{
    ll ans=1;
    ll pl=abs(ed-beg);
    ans+=abs(cur-beg);
    ans+=pl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("VISIT.INP","r",stdin);
    freopen("VISIT.OUT","w",stdout);
    ll n;
    cin>>n;
    dp[0][0]=mp(1,0);
    dp[0][1]=mp(1,0);
    for(ll i=1;i<=n;i++)
    {
        ll a,b;
        cin>>a>>b;
        dp[i][0].fi=b;
        dp[i][1].fi=a;

        dp[i][0].se=dp[i-1][0].se+cal(dp[i-1][0].fi,b,a);
        dp[i][0].se=min(dp[i][0].se,dp[i-1][1].se+cal(dp[i-1][1].fi,b,a));

        dp[i][1].se=dp[i-1][0].se+cal(dp[i-1][0].fi,a,b);
        dp[i][1].se=min(dp[i][1].se,dp[i-1][1].se+cal(dp[i-1][1].fi,a,b));

        if(i==1)
        {
            dp[i][0].se--;
            dp[i][1].se--;
        }
    }
    ll ans=INT_MAX;
    ans=min(ans,n-dp[n][0].fi+dp[n][0].se);
    ans=min(ans,n-dp[n][1].fi+dp[n][1].se);
    cout<<ans<<endl;
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<dp[i][0].fi<<" " <<dp[i][0].se<<" "<< " " <<dp[i][1].fi<<" "<<dp[i][1].se<<endl;
//    }

}
