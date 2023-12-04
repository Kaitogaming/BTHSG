#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e4+4;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANHEM.INP","r",stdin);
    freopen("ANHEM.OUT","w",stdout);
    ll a,b;
    ll sum1=0,sum2=0;
    cin>>a>>b;
    for(ll i=2;i<=a/2;i++)
    {
        if(a%i==0)
        {
            sum1+=i;
        }
    }
    for(ll i=2;i<=b/2;i++)
    {
        if(b%i==0)
        {
            sum2+=i;
        }
    }
    if(sum1==sum2 && sum1!=0)
    {
        cout<<"YES";
        return 0;
    }else
    {
        cout<<"NO";
        return 0;
    }
}
