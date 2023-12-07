#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);;
    cin.tie(0);
//    freopen("BAI5.INP","r",stdin);
//    freopen("BAI5.OUT","w",stdout);
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    if(n<10)
    {
        cout<<sum;
        return 0;
    }
    while(n>=10)
    {
        sum-=a[n-10];
        n-=10;
    }
    cout<<sum;
}
