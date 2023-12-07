#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+2;
using namespace std;
bool snt[N];
vector<ll> check;
ll ans[N+5];
ll mx=0;
ll mn=INT_MAX;
pair<ll,ll> k;
ll l,r;
ll kq=0;
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
          ll x=check[i];
         for(ll j=3;j<=43;j++)
         {
             x*=check[i];
             if(x>r || x<=0)
             {
                 break;
             }
             if(x>=l && snt[j])
             {
                 kq++;
             }
         }
      }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    first();
    cin>>l>>r;
    second();
    //solve();
    //cout<<mx<<" "<<mn<<endl;
    //cout<<k.first<<" "<<k.second<<endl;
    cout<<kq;
}
