#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+5;
using namespace std;
bool snt[N];
void first()
{
    memset(snt,1,sizeof(snt));
    snt[0]=0;
    snt[1]=0;
    for(ll i=2;i<=N/10;i++)
    {
        if(snt[i])
        for(ll j=i+i;j<=N/10;j+=i)
        {
            snt[j]=0;
        }
    }
}
vector <ll> ans;
bool check(ll x)
{
    ll sum=0;
    while(x)
    {
        sum+=(x%10)*(x%10);
        x/=10;
    }
    return snt[sum]==1;
}
void solve()
{
    ans.push_back(0);
    for(ll i=11;i<=N*10;i++)
    {
        if(check(i))
        {
            ans.push_back(i);
        }
    }
}
int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     freopen("BEAUTY.INP","r",stdin);
     freopen("BEAUTY.OUT","w",stdout);
     first();
     solve();
     ll a;
     while(cin>>a)
     {
         cout<<ans[a]<<endl;
     }
}
