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
    string s,s1;
    getline(cin,s);
    s+='1';
    getline(cin,s1);
    char cur;
    ll cnt=0;
    string ans;
    for(ll i=0;i<s.size();i++)
    {
        if(i==0)
        {
            cur=s[i];
            cnt=1;
            continue;
        }
        if(cur!=s[i] && i!=0)
        {
            if(cnt>1)
            ans+=cnt+'0';
            ans+=cur;
            cnt=1;
            cur=s[i];
        }else
        {
            cnt++;
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<s1.size();i+=2)
    {
        ll dem=s1[i]-'0';
        for(ll j=0;j<dem;j++)
        {
            cout<<s1[i+1];
        }
    }
}
