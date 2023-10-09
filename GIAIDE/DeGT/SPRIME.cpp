#include <bits/stdc++.h>
#define ll long long
const int N=3e6+5;
using namespace std;
ll dp[N];
bool snt[N];
bool check(ll x)
{
    if(snt[x]==0) return 0;
    ll ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans%5==0;
}
void first()
{
    snt[1]=0;
    for(ll i=2;i<=N;i++)
    {
        if(snt[i]==0) continue;
        for(ll j=i+i;j<=N;j+=i)
            {
                snt[j]=0;
            }
    }
}
void second()
{
    for(ll i=1;i<=N;i++)
    {
        dp[i]=dp[i-1]+check(i);
    }
}
void solve()
{
    ll l,r;
    cin>>l>>r;
    cout<<dp[r]-dp[l-1]<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    first();
    second();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
