#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.second<b.second;
}
ll n,r,dem=1;
pair <ll,ll> a[200000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n;
    if(n==0) cout<<0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,compare);
    r=a[0].second;
    for(ll i=1;i<n;i++)
    {
        if(a[i].first>=r)
        {
            r=a[i].second;
            dem++;
        }
    }
    cout<<dem;
}
