#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=64e3+5;
using namespace std;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXP.INP","r",stdin);
    freopen("EXP.OUT","w",stdout);
    ll n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='+')
        {
            a[i]=1;
        }
    }
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        ll mnx=INT_MAX;
        ll mny=INT_MAX;
        ll mxx=INT_MIN;
        ll mxy=INT_MIN;
        while(x)
        {
            mxx=max(mxx,x%10);
            mnx=min(mnx,x%10);
            x/=10;
        }
        while(y)
        {
            mxy=max(mxy,y%10);
            mny=min(mny,y%10);
            y/=10;
        }
        if(a[i])
        {
            ans+=mxy*mxx;
        }else
        {
            ans-=mnx*mny;
        }
    }
    cout<<ans;
}
