#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,x,y,ans,lsum=0,rsum=0;
multiset<ll> l;
multiset<ll> r;
ll a[200005];

int main()
{
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(i<k)
        {
            r.insert(a[i]);
            rsum+=a[i];
        }
    }
    y=(k+1)/2;
    while(y--)
    {
        l.insert(*r.begin());
        lsum+=*r.begin();
        rsum-=*r.begin();
        r.erase(r.begin());
    }
    y=(k+1)/2;
    for(ll i=k;i<n;i++)
    {
        if(r.size())
        {
            ans=0;
            x=*(--l.end());
            ans=x*l.size()-lsum;
            ans+=rsum-x*(r.size());

            x=*r.begin();
            ll w=rsum-x*r.size();
            w+=x*l.size()-lsum;
            ans=min(ans,w);
            cout<<ans<<" ";
        } else {
            cout<<0<<" ";
        }

        x=*(--l.end());
        if(a[i-k]<=x)
        {
            l.erase(l.find(a[i-k]));
            lsum-=a[i-k];
        }
        else
        {
            if(r.size())
                r.erase(r.find(a[i-k]));
            rsum-=a[i-k];
        }

        if(a[i]<=x)
        {
            l.insert(a[i]);
            lsum+=a[i];
        }
        else
        {
            r.insert(a[i]);
            rsum+=a[i];
        }

        if(l.size()<y)
        {
            l.insert(*r.begin());
            lsum+=*r.begin();
            if(r.size())
                rsum-=*r.begin();
            if(r.size())
                r.erase(r.begin());
        }
        else
        {
            r.insert(*(--l.end()));
            lsum-=*(--l.end());
            rsum+=*(--l.end());
            l.erase(--l.end());
        }
    }
    if(r.size())
        {
            ans=0;
            x=*(--l.end());
            ans=x*l.size()-lsum;
            ans+=rsum-x*(r.size());

            x=*r.begin();
            ll w=rsum-x*r.size();
            w+=x*l.size()-lsum;
            ans=min(ans,w);
            cout<<ans<<" ";
        } else {
            cout<<0<<" ";
        }
    return 0;
}
