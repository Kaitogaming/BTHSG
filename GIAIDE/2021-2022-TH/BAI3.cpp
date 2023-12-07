#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
    ll n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI3.INP","r",stdin);
    //freopen("BAI3.OUT","w",stdout);
    cin>>n>>k;
    ll ans=0;
    multiset <ll> s;
    multiset <ll>::iterator it;
    for(ll i=0;i<n;i++)
    {
        //cout<<ans<<" ";
        ll a;
        cin>>a;
        if(s.size()==0)
        {
            s.insert(a);
            continue;
        }else if(s.size()==1)
        {
             it=s.end();
             it--;
             ll x=*it;
             if(abs(x-a)>=k)
             {
                 s.insert(a);
             }else
             {
                 ans+=x;
                 s.clear();
                 s.insert(a);
             }
             continue;
        }

        it=s.lower_bound(a);
        if(it==s.end())
        {
            it--;
            ll x=*it;
            if(a-x>=k)
            {
                s.insert(a);
            }else
            {
                ans+=x;
                s.clear();
                s.insert(a);
            }
            continue;
        }else if(it==s.begin())
        {
            ll x=*it;
            if(x-a>=k)
            {
                s.insert(a);
            }else
            {
                ans+=*(--s.end());
                s.clear();
                s.insert(a);
            }
            continue;
        }
        ll r=*it;
        ll l=*(--it);
        if(a-l>=k && r-a>=k)
        {
            s.insert(a);
        }else
        {
            ans+=*(--s.end());
            s.clear();
            s.insert(a);
        }
    }
    cout<<ans+(*(--s.end()));
}
