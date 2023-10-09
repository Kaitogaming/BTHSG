#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cal(ll x,ll y)
{
    return (x+1)/2-1-y;
}
int main()
{
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    ll n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<1;
        return 0;
    }else if(k==2)
    {
        cout<<cal(n,0);
        return 0;
    }else if(k==3)
    {

        ll ans=0;
        for(ll i=1;i<=n/3;i++)
        {
            ll check=cal(n-i,i);
            if (check>0)
            {
                ans+=check;
            }
        }
        cout<<ans;
        return 0;

    }else if(k==4)
    {
        ll ans=0;
        for(ll i=1;i<=n/4;i++)
        {
            for(ll j=i+1;j<=(n-i)/3;j++)
            {
                ll check=n-i-j;
                if(j>=check/2) break;
                ll val=cal(check,j);
                if(val>0) ans+=val;
            }
        }
        cout<<ans;
        return 0;
    }
}
