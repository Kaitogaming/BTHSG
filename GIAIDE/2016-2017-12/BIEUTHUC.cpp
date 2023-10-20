#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+5;
using namespace std;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BIEUTHUC.INP","r",stdin);
    freopen("BIEUTHUC.OUT","w",stdout);
    ll n,k;
    cin>>n>>k;
    ll sum;
    cin>>sum;
    for(ll i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n-1);
    ll i=n-2;
    while(k)
    {
        sum+=a[i];
        i--;
        k--;
    }
    while(i>=0)
    {
        sum-=a[i];
        i--;
    }
    cout<<sum;
}
