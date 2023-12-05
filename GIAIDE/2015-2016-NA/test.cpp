#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("RADIO.INP","w",stdout);
    ll n=830000/3;
    srand(time(0));
    //cout<<n<<endl;
    string s;
    for(ll i=0;i<n;i++)
    {
        ll x=rand()%26;
        char s1='a'+x;
        s+=s1;
    }
    cout<<s.size()*3<<endl;
    //cout<<s<<s<<s;
}
