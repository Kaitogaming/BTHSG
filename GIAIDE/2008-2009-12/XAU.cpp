#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XAU.INP","r",stdin);
    freopen("XAU.OUT","w",stdout);
    ll cnt=0;
    string s,s1;
    cin>>s>>s1;
    if(s.size()>s1.size())
    {
        cout<<0;
        return 0;
    }
    for(ll i=0;i<=s1.size()-s.size();i++)
    {
        string s2=s1.substr(i,s.size());
        if(s2==s) cnt++;
    }
    cout<<cnt;
}
