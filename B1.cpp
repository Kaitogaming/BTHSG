#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d,gcd,lcm,x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    gcd=__gcd(b,d);
    lcm=b*d/gcd;
    a=a*lcm/b;
    c=c*lcm/d;
    gcd=__gcd(a,c);
    x=__gcd(gcd,lcm);
    cout<<gcd/x<<endl<<lcm/x;

}
