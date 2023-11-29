#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second.first
#define th second.second.first
#define fo second.second.second
const int N=5e3+5;
using namespace std;
pair<ll,pair<ll,pair<ll,ll>> > a[N];
ll dp[N];
ll n,s;
bool compare(pair<ll,pair<ll,pair<ll,ll>>> x,pair<ll,pair<ll,pair<ll,ll>>> y)
{
    return x.th<y.th;
}
double dis(ll x,ll y)
{
    return sqrt((a[x].fi-a[y].fi)*(a[x].fi-a[y].fi)+(a[x].se-a[y].se)*(a[x].se-a[y].se));
}
bool cal(ll x,ll y)
{
    ll t=a[x].th-a[y].th;
    return t*s>=dis(x,y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CUOCTHI.INP","r",stdin);
    freopen("CUOCTHI.OUT","w",stdout);
    ll ans=0,cs=0;
    cin>>n>>s;
    a[0].fi=0;
    a[0].se=0;
    a[0].th=0;
    for(ll i=1;i<=n;i++)
    {
          cin>>a[i].fi>>a[i].se>>a[i].th;
          a[i].fo=i;
    }
    sort(a,a+n+1,compare);
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<a[i].fi<<" "<<a[i].se<<" "<<a[i].th<<" "<<a[i].fo<<" "<<i<<endl;
//    }
//    cout<<endl;
    for(ll i=1;i<=n;i++)
    {
         for(ll j=i-1;j>=0;j--)
         {
              //cout<<i<<" "<<j<<" "<<dis(i,j)<<" "<<t<<" "<<s<<endl;
              if(cal(i,j))
              {
                  dp[i]=max(dp[i],dp[j]+1);
                  if(dp[i]>ans)
                  {
                      ans=dp[i];
                      cs=i;
                  }
              }
         }
    }
//    cout<<cs<<endl;
//    for(ll i=0;i<=n;i++)
//    {
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    vector <ll> kq;
    kq.push_back(a[cs].fo);
    for(ll i=cs-1;i>=0;i--)
    {
        if(dp[i]==dp[cs]-1 && cal(cs,i))
        {
            //cout<<dp[i]<<" "<<i<<" ";
            cs=i;
            //cout<<dp[cs]<<" "<<cs<<endl;
            kq.push_back(a[cs].fo);
            if(dp[cs]==1)
            {
                break;
            }
        }
    }
    reverse(kq.begin(),kq.end());
    cout<<ans<<endl;
    for(ll i=0;i<kq.size();i++)
    {
        cout<<kq[i]<<endl;
    }
    //cout<<ans;

}
