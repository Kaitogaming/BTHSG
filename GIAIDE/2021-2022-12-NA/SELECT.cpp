#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
    map<ll,ll> mp;
    ll a,cnt=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SELECT.INP","r",stdin);
//    freopen("SELECT.OUT","w",stdout);
    while(cin>>a)
    {
        cnt++;
        mp[a]++;
    }
    map<ll,ll>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>cnt/2)
        {
            cout<<it->first;
            return 0;
        }
    }
    cout<<0;
}
