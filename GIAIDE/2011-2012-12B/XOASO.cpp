#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("XOASO.INP","r",stdin);
//    freopen("XOASO.OUT","w",stdout);
    string s;
    cin>>s;
    ll k;
    pair<ll,ll> cur=make_pair(-1,10);
    cin>>k;
    k=s.size()-k;
    for(;k>0;k--)
    {
        for(ll i=cur.first+1;i<=s.size()-k;i++)
        {
            if(s[i]-'0'<cur.second)
            {
                cur.second=s[i]-'0';
                cur.first=i;
            }
        }
        cout<<cur.second;
        cur.second=10;
    }

}
