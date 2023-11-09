#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool check(ll x)
{
    return x==2 || x==3 || x==5 || x==7;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PASS.INP","r",stdin);
    ll n;
    cin>>n;
    string s;
    ll cur=0;
    ll mx=0;
    while(cin>>s)
    {
        cur=0;
        for(ll i=0; i<s.size(); i++)
        {
            if(check(s[i]-'0'))
            {
                cur++;
                mx=max(mx,cur);
            }
            else
            {
                cur=0;
            }
        }
    }
    cout<<mx;
}
