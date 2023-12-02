#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
vector <ll> ans;
bool snt[N];
bool check[N];
void sang()
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
void solve(ll x)
{
//    if(snt[x])
//    {
//        if(check[x]==0)
//        {
//            ans.push_back(x);
//            check[x]=1;
//        }
//        return;
//    }
    for(ll i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            ll cur=i-1;
            ll y=x/i+1;
            cur*=y;
            if(check[cur]==0)
            {
                ans.push_back(cur);
                check[cur]=1;
                solve(cur);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("ZEROPATH.INP","r",stdin);
//    freopen("ZEROPATH.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    ll n;
    cin>>n;
    sang();
    solve(n);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
