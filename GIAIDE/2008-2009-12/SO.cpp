#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SO.INP","r",stdin);
    freopen("SO.OUT","w",stdout);
    ll a[10005];
    ll b,i=1,sum=0,mx=LLONG_MIN;
    while(cin>>b)
    {
        a[i]=b;
        sum+=b;
        mx=max(mx,b);
        i++;
    }
    cout<<sum<<endl;
    cout<<mx<<endl;
    for(ll j=1;j<i;j++)
    {
        if(a[j]==mx) cout<<j<<" ";
    }
}
