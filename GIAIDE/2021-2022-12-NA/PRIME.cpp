#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll dp[N];
bool snt[N];
void pre()
{
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
ll reve(ll x)
{
    ll y=0;
    while(x)
    {
        y*=10;
        y+=x%10;
        x/=10;
    }
    return y;
}
bool check(ll x)
{
    return snt[x] && x==reve(x);
}
void solve()
{
    for(ll i=2;i<=N;i++)
    {
        dp[i]=dp[i-1];
        if(check(i)==0) continue;
        dp[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRIME.INP","r",stdin);
    freopen("PRIME.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    ll a,b;
    pre();
    solve();
    cin>>a>>b;
    cout<<dp[b]-dp[a-1];
}
