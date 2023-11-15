#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,c,x,y,z;
    ll sum=0;
    cin>>a>>b>>c>>x>>y>>z;
    sum=a*x+b*y;
    z-=x+y;
    sum+=z*c;
    cout<<sum;
}
