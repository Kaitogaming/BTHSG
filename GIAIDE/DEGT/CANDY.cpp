#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans=0,x,c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    cin>>n>>k;
    if(n<k+(k*k-1)/2)
    {
        cout<<0;
        return 0;
    }
    if(k==1)
    {
        cout<<1;
        return 0;
    }
    if(k==2)
    {
        if(n%2==0)
        {
            cout<<n/2-1;
        }
        else cout<<n/2;
        return 0;
    }
    if(k==3)
    {
        for(ll i=1; i<n/3; i++)
        {
            x=n;
            x-=i;
            if(x%2==0)
            {
                ans+=x/2-i-1;
            }
            else ans+=x/2-i;
        }
        cout<<ans;
        return 0;
    }
    if(k==4)
    {
        for(ll i=1;i<n/4-1;i++)
        {
            x=n;
            x-=i;
            for(ll j=i+1;j<x/3;j++)
            {
                c=x-j;
                if(c%2==0)
            {
                ans+=c/2-1-j;
            }
            else ans+=c/2-j;
            }
        }
        cout<<ans;
    }
}
