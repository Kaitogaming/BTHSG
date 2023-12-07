#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+2;
using namespace std;
bool snt[N];
vector<ll> check;
ll ans[N+5];
ll mx=0;
ll mn=INT_MAX;
pair<ll,ll> k;
ll mu(ll a,ll b)
{
    bool kq=0;
    if(a==0) return 0;
    ll x=1;
    while(b)
    {
        x*=a;
        b--;
        if(x>N)
        {
            kq=1;
            break;
        }
    }
    if(kq) return -1;
    return x;
}
void first()
{
    memset(snt,1,sizeof(snt));
    snt[0]=0;
    snt[1]=0;
    for(ll i=2; i<=N; i++)
    {
        if(snt[i])
        {
            //cout<<i<<endl;
            check.push_back(i);
            for(ll j=i+i; j<=N; j+=i)
            {
                snt[j]=0;
            }
        }
    }
}
void second()
{
    //cout<<check.size()<<endl;
      for(ll i=0;i<check.size();i++)
      {
          for(ll j=0;j<check.size();j++)
          {
              ll cur=check[i]-1;
              ll b=check[j];
              ll x=mu(b,cur);
              if(x>N || x<0) break;

              mx=max(mx,x);
              if(x<mn)
              {
                  mn=x;
                  k.first=b;
                  k.second=cur;
              }

              //cout<<b<<" "<<cur<<" "<<x<<endl;
              ans[x]=1;

          }
      }
}
void solve()
{
    for(ll i=2;i<=N;i++)
    {
        ans[i]+=ans[i-1];
//        if(i<100)
//        cout<<ans[i]<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    first();
    second();
    solve();
    //cout<<mx<<" "<<mn<<endl;
    //cout<<k.first<<" "<<k.second<<endl;
    ll l,r;
    cin>>l>>r;
    cout<<ans[r]-ans[l-1];
}
