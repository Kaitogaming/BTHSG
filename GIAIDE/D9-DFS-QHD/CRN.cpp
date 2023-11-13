#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll sz[N];
ll p[N];
bool kt[N];
vector <ll> ans;
pair<bool,ll> dp[N];
bool kiem(ll x)
{
    while(x)
    {
        ll test=x%10;
        x/=10;
        if(test!=7 && test!=4)
        {
            return 0;
        }
    }
    return 1;
}
ll find(ll x)
{
    while(x!=p[x])
    {
        x=p[x]=p[p[x]];
    }
    return x;
}
void hop(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    p[y]=x;
    return;
}
bool check(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        sz[i]=1;
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        hop(a,b);
//        adj[a].push_back(b);
//        adj[b].push_back(a);
    }
    cout<<endl;
    for(ll i=1;i<=n;i++)
    {
        if(kt[find(i)]) continue;
        kt[find(i)]=1;
        ans.push_back(sz[find(i)]);
    }
    sort(ans.begin(),ans.end());
    ll mx=0;
//    for(ll i=0;i<ans.size();i++)
//    {
//        cout<<ans[i]<<" ";
//    }
//    cout<<endl;
    dp[0]={1,-1};
    for(ll i=0;i<ans.size();i++)
    {
        for(ll j=mx;j>=0;j--)
        {
            if(dp[j].first==0) continue;
            dp[j+ans[i]]={1,dp[j].second+1};
            mx=max(mx,j+ans[i]);
            if(kiem(j+ans[i]))
            {
                cout<<dp[j].second+1;
                return 0;
            }
        }
    }
    cout<<-1;
}
