#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("RADIO.INP","r",stdin);
    freopen("RADIO.OUT","w",stdout);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l=0,r=n;
    for(ll i=1;i<=n;i++)
    {
        string check=s.substr(0,i);
        bool kt=1;
        for(ll j=i;j<n;j+=i)
        {
           for(ll k=0;k<i && j+k<n;k++)
           {
               if(s[j+k]!=check[k])
               {
                   kt=0;
                   break;
               }
           }
           if(kt==0) break;
        }
        if(kt)
        {
            cout<<i;
            //cout<<endl<<check;
            return 0;
        }
    }
}
