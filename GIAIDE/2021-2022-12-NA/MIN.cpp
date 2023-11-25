#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
    ll k;
    string s1;
    string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MIN.INP","r",stdin);
    //freopen("MIN.OUT","w",stdout);
    cin>>k;
    cin>>s1;
    for(ll i=0;i<s1.size();i++)
    {
        if(s1[i]-'0'>=0 && s1[i]-'0'<=9) s+=s1[i];
    }
    //cout<<s<<endl;
    ll cnt=s.size()-k;
    ll dem=0;
    pair<ll,ll> cur=make_pair(-1,10);
    for(dem=0;dem<k;dem++)
    {
        for(ll i=cur.first+1;i<=cnt+dem;i++)
        {
             if(s[i]-'0'<cur.second)
             {
                 cur.first=i;
                 cur.second=s[i]-'0';
             }
        }
        cout<<cur.second;
        cur.second=10;
    }
}
