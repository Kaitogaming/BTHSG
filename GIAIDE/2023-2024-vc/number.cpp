#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e3+5;
using namespace std;
ll ans=0;
void solve(ll x)
{
    ll c=x;
    if(x<=9) return;
    ll k=INT_MAX;
    while(x)
    {
        if(x%10>k) return;
        k=x%10;
        x/=10;
    }
    ans++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        solve(a);
    }
    cout<<n-ans;
}
