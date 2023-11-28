#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ShenYun.inp","r",stdin);
    freopen("ShenYun.out","w",stdout);
    ll n,a,b;
    cin>>n>>a>>b;
    ll x=__gcd(a,b);
    if(b>a) swap(a,b);
    ll c=a;
    c/=x;
    x=c*b;
    cout<<n/x;
}

