#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    ll n,k;
    cin>>n>>k;
    string s;
    for(ll i=0;i<n;i++)
    {
        s+="0";
    }
    if(n*9<k)
    {
        cout<<-1;
        return 0;
    }
    for(ll i=0;i<n;i++)
    {
        ll x=min((ll)9,k);
        char chien='0'+x;
        //cout<<chien<<" "<<x<<endl;
        s[i]=chien;
        k-=x;
    }
    cout<<s;
}
