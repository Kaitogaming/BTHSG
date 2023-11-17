#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XAUGON.INP","r",stdin);
    freopen("XAUGON.OUT","w",stdout);
    string s;
    cin>>s;
    s="1"+s;
    for(ll i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            cout<<s[i];
        }
    }
}
