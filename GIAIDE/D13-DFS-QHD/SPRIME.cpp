#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
const int N=1e3+5;;
using namespace std;
bool snt[N];
pair<ll,ll> dp[N][2];
void first()
{
    memset(snt,1,sizeof(snt));
    snt[0]=0;
    snt[1]=0;
    for(ll i=2;i<=N;i++)
    {
        if(snt[i])
        for(ll j=i+i;j<=N;j+=i)
        {
            snt[j]=0;
        }
    }
}
void solve()
{
//    dp[1][0]=make_pair(INT_MIN,0);
//    dp[1][1]=make_pair(INT_MIN,0);
      dp[0][0]=make_pair(0,-1);
      dp[0][1]=make_pair(0,-1);
    for(ll i=2;i<=N;i++)
    {
        for(ll j=i;j>=2;j--)
        {
            if(snt[j]==0) continue;
            //if(i<=10)
            //cout<<i<<" "<<j<<" "<<dp[i-j][0].se<<" "<<dp[i-j][0].fi<<" "<<dp[i-j][1].fi<<" "<<dp[i-j][1].se<<" "<<dp[i][0].fi<<endl;
            if(dp[i-j][0].se && j>dp[i-j][0].se && dp[i-j][0].fi+1>dp[i][0].fi)
            {
                dp[i][0].fi=dp[i-j][0].fi+1;
                dp[i][0].se=j;
//                if(i<=10)
//                cout<<i<<" "<<j<<" "<<dp[i][0].fi<<" "<<dp[i][0].se<<" A"<<endl;
            }else if(dp[i-j][0].se && j==dp[i-j][0].se && dp[i-j][0].fi+1>dp[i][1].fi)
            {
                dp[i][1].fi=dp[i-j][0].fi+1;
                dp[i][1].se=j;
//                if(i<=10)
//                cout<<i<<" "<<j<<" "<<dp[i][1].fi<<" "<<dp[i][1].se<<" B"<<endl;
            }else if(dp[i-j][1].se && j>dp[i-j][1].se && dp[i-j][1].fi+1>dp[i][1].fi)
            {
                dp[i][1].fi=dp[i-j][1].fi+1;
                dp[i][1].se=j;
//                if(i<=10)
//                cout<<i<<" "<<j<<" "<<dp[i][1].fi<<" "<<dp[i][1].se<<" C"<<endl;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    ll a;
    first();
    solve();
//    for(ll i=0;i<=11;i++)
//    {
//        cout<<dp[i][0].fi<<" "<<dp[i][0].se<<" "<<dp[i][1].fi<<" "<<dp[i][1].se<<endl;
//    }
    while(cin>>a)
    {
        if(dp[a][0].fi)
        {
           cout<<dp[a][0].fi<<endl;
        }else
        {
            cout<<dp[a][1].fi<<endl;
        }
    }
    //1 1 1 2 2 2 2 2
}
