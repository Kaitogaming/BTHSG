#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>c)
    {
        swap(a,c);
        swap(b,d);
    }
    if(b<c)
    {
        cout<<0;
        return 0;
    }
    cout<<min(d,b)-c+1;
}
