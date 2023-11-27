#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
const int N=1e3+5;
using namespace std;
    ll n,d;
pair<ll,ll> a[N];
bool check[N];
ll cnt=0;
double calc(ll x,ll y)
{
    return sqrt((a[x].fi-a[y].fi)*(a[x].fi-a[y].fi)+(a[x].se-a[y].se)*(a[x].se-a[y].se));
}
bool kt(ll x,ll y)
{
    return calc(x,y)<d;
}
void dfs(ll x)
{
    check[x]=1;
    for(ll i=0;i<n;i++)
    {
        if(check[i]) continue;
        //cout<<calc(x,i)<<endl;
        //<<" "<<x<<" "<<i<<" "<<a[x].fi<<" "<<a[x].se<<" "<<a[i].fi<<" "<<a[i].se<<" ";
        //cout<<sqrt((a[x].fi-a[i].fi)*(a[x].fi-a[i].fi)+(a[x].se-a[i].se)*(a[x].se-a[i].se))<<endl;
        if(kt(x,i)) dfs(i);
        //cout<<i<<" dcm"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("POINTS.INP","r",stdin);
    freopen("POINTS.OUT","w",stdout);
    cin>>n>>d;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    for(ll i=0;i<n;i++)
    {
        if(check[i]==0)
        {
            dfs(i);
            cnt++;
            //cout<<i<<endl;
        }
    }
    cout<<cnt;
}
