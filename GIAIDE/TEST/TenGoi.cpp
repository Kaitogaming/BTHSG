#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e4+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TenGoi.inp","r",stdin);
    freopen("TenGoi.out","w",stdout);
    pair<ll,ll> ans=make_pair(0,0);
    ll n;
    cin>>n;
    string s;
    getline(cin,s);
    for(ll i=0;i<n;i++)
    {
        getline(cin,s);
        //cout<<s<<endl;
        ll beg=0;
        for(ll j=0;j<s.size();j++)
        {
             if(s[j]=='W' || s[j]=='A' || s[j]=='R')
             {
                 beg=j+1;
                 //cout<<i<<" "<<j<<endl;
             }else
             {
                 ll calc=j-beg+1;
                 if(calc>ans.first)
                 {
                     //cout<<i<<" "<<j<<" "<<beg<<endl;
                     ans.first=calc;
                     ans.second=1;
                 }else if(calc==ans.first)
                 {
                     ans.second++;
                 }
             }
        }
    }
    if(ans.first)
    {
        cout<<ans.first<<" "<<ans.second;
        return 0;
    }else
    {
        cout<<"NO";
        return 0;
    }
}
