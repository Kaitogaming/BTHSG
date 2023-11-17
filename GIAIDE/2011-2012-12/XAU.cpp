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
            cout<<cnt;
            cout<<cur;
            cnt=1;
            cur=s[i];
        }else
        {
            cnt++;
        }
    }
    cout<<endl;
    ll cnt1;
    cnt1=0;
    for(ll i=0;i<s1.size();i++)
    {
          if(s1[i]-'0'>9 || s1[i]-'0'<0)
          {
              if(cnt1==0) cout<<s1[i];
              //cout<<cnt1<<" dcm "<<endl;
              for(ll j=0;j<cnt1;j++)
              {
                  cout<<s1[i];
              }
              cnt1=0;

          }else
          {
              cnt1*=10;
              cnt1+=s1[i]-'0';
          }
    }
}
