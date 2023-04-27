#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    vector <ll> a;
    cin>>n;
    while(n--)
    {
        ll b;
        cin>>b;
        ll cs=lower_bound(a.begin(),a.end(),b)-a.begin();
        if(cs<a.size())
        {
            a[cs]=b;
        }else
        {
            a.push_back(b);
        }
    }
    cout<<a.size();
}
