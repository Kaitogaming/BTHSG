#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
map<string,bool> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    ll ans=1;
    for(ll sz=s.size()-1;sz>=1;sz--)
    {
        mp.clear();
        for(ll i=0;i<=s.size()-sz;i++)
        {
             mp[s.substr(i,sz)]=1;
        }
        ans+=mp.size();
    }
    cout<<ans;
}
