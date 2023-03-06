#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l=0,ans=0,check;
ll a[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAPSO.INP","r",stdin);
    freopen("CAPSO.OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
        {
            if(i!=l)
            {
                check=i-l+1;
                if(check%2==0)
                {
                ans+=check/2*(check-1);
                }else ans+=(check-1)/2*check;
            }
            l=i+1;
        }
    }
    if(a[n-1]==a[n-2])
    {
        check=n-1-l+1;
        if(check%2==0)
        {
        ans+=check/2*(check-1);
        }else ans+=(check-1)/2*check;
    }
    cout<<ans;
}
