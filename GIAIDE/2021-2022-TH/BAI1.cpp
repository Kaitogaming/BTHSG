#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const ll N=1e18+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ll n,a,b;
    cin>>n>>a>>b;
    cout<<max((ll) 0,a-b)<<" "<<n-b;
}
