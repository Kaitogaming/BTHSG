#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,t,ans=0;
ll dp[3000005];
bool check[3000005];
bool kt(ll a)
{
    ll sum=0;
    while(a!=0)
    {
        sum+=a%10;
        a/=10;
    }
    if(sum%5==0) return 1;
    return 0;
}
void snt()
{
   memset(check,1,sizeof(check));
   check[0]=0;
   check[1]=0;
   for(ll i=2;i*i<3000005;i++)
   {
       if(check[i]==1)
       for(ll j=i*i;j<=3000005;j+=i)
       {
           check[j]=0;
       }
   }
   dp[0]=0;
   for(ll i=1;i<=3000005;i++)
   {
       dp[i]+=dp[i-1];
       if(check[i] && kt(i))
       {
           dp[i]++;
       }
   }

}
void solve()
{
    cin>>a>>b;
    cout<<dp[b]-dp[a-1]<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    cin>>t;
    snt();
//    for(ll i=0;i<50;i++)
//    {
//        cout<<check[i]<<' ';
//    }
    while(t--)
    {
        solve();
    }
}
