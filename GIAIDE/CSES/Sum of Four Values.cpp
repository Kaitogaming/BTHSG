#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x;
pair <ll,ll> a[5000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(ll i=0; i<n-3; i++)
    {
        if(a[i].first>x) break;
        for(ll j=i+1; j<n-2; j++)
        {
            ll b=a[i].first+a[j].first;
            if(b>=x) break;
            for(ll z=j+1;z<n-1;z++)
            {
                b=a[i].first+a[j].first+a[z].first;
                if(b>=x) break;
                ll cs=lower_bound(a+z+1,a+n,make_pair(x-b,(ll) 0))-a;
            if(b+a[cs].first==x)
            {
                cout<<a[i].second<<' '<<a[j].second<<' '<<a[z].second<<" "<<a[cs].second;
                return 0;
            }
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
