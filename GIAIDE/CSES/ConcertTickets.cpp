#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m,n,t;
map <ll,ll> mp;
map <ll,ll>::iterator it;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        cin>>t;
        mp[t]++;
    }
    for(ll i=0;i<m;i++)
    {
        cin>>t;
        it=mp.upper_bound(t);
        if(it==mp.begin())
        {
            cout<<-1<<endl;
            continue;
        }else
        {
            it--;
            cout<<it->first<<endl;
            it->second--;
            if(it->second == 0)
            {
                mp.erase(it);
            }
        }
    }
}
