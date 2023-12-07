#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=2e6+5;
using namespace std;
    string s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    ll n=0;
    while(cin>>s[n])
    {
       n++;
    }
    n/=2;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        bool kt=0;
        string check=s[i+n];
        if(s[i][0]!=check[0]) continue;
        for(ll j=1;j<check.size();j++)
        {
            if(s[i][j]!=check[j])
            {
                if(s[i][j]!=s[i][j-1])
                {
                    kt=1;
                    break;
                }
                s[i].erase(j-1,1);
                j--;
            }
        }
        if(kt) continue;
        while(s[i].size()>check.size())
        {
            if(s[i][check.size()]!=s[i][check.size()-1])
            {
                break;
            }
            s[i].erase(check.size(),1);
        }
        if(s[i]==check)
        {
            ans++;
        }
    }
    cout<<ans;
}
