#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CuocThi.inp","r",stdin);
    freopen("CuocThi.out","w",stdout);
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
//    for(ll i=0;i<n;i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    for(ll i=0;i<q;i++)
    {
        ll c,d;
        cin>>c>>d;
        ll c1=lower_bound(a,a+n,c)-a;
        ll d1=upper_bound(a,a+n,d)-a-1;
        cout<<d1-c1+1<<endl;
    }
}
