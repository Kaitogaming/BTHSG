#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,j=0,ans=0;
ll a[200005];
int main()
{
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map <ll,ll> mp;
    multiset <ll> s;
    for(ll i=0;i<n;i++)
    {
        mp[a[i]]++;
        s.insert(a[i]);
        if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[a[j]]--;
                s.erase(s.find(a[j]));
                if(mp[a[j]]==0)
                {
                    mp.erase(a[j]);
                }
                j++;
            }
        }
        ans+=s.size();
    }
    cout<<ans;
}
