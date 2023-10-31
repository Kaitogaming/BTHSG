#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
ll a[10];
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIENKINH.INP","r",stdin);
    freopen("DIENKINH.OUT","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll dem=0;
    string s="1234567";
    for(ll i=0;i<7-n;i++)
    {
        s.erase(s.end()-1);
    }
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    while(next_permutation(s.begin(),s.end()))
    {
        for(ll i=0;i<s.size();i++)
        {
            ll b=s[i]-'1';
            cout<<a[b]<<" ";
        }
        dem++;
        cout<<endl;
    }
    cout<<dem+1;
}
