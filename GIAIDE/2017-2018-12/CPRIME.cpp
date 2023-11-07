#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=5e6+5;
bool snt[N+5];
ll dp[N+5];
void pre()
{
   snt[1]=0;
   snt[0]=0;
   for(ll i=2;i<N;i++)
   {
       if(snt[i])
       for(ll j=i+i;j<N;j+=i)
       {
           snt[j]=0;
       }
   }
   for(ll i=2;i<N;i++)
   {
        dp[i]=dp[i-1];
        if(snt[i]) dp[i]++;
   }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CPRIME.INP","r",stdin);
    freopen("CPRIME.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    ll n;
    pre();
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<endl;
    }
}
