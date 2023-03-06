#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a1,a2,n,ans=INT_MIN;
ll a[1000006];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    a1=a[0];
    a2=a[1];
    if(a1<a2) swap(a1,a2);
    for(ll i=2;i<n;i++)
    {
        if(a[i]>a2)
        {
            a2=a[i];
        }else
        if(a[i]>a1)
        {
            a1=a2;
            a2=a1;

        }
        ans=max(ans,a2-a[i]+a2);
    }
    cout<<ans;
}
