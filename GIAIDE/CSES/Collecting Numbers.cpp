#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair <ll,ll> a[200005];
ll n,dem=1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        if(a[i].second<a[i-1].second)
        {
            dem++;
        }
    }
    cout<<dem;
}
