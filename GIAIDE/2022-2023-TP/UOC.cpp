#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e12+3;
using namespace std;
ll n;
//void snt()
//{
//    memset(check,1,sizeof(check));
//    check[1]=0;
//    check[0]=0;
//    for(ll i=2;i*i<n;i++)
//    {
//        if(check[i])
//        {
//            for(ll j=i*i;i*j<=n;j+=i)
//            {
//                check[j]=0;
//            }
//        }
//    }
//}
void sub1()
{
    ll dem=0;
    for(ll i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            dem++;
        }
    }
    cout<<dem;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("UOC.INP","r",stdin);
    freopen("UOC.OUT","w",stdout);
    cin>>n;
    if(n<=1e6)
    {
        sub1();
        return 0;
    }
    ll ans=1;
    for(ll i=2;i*i<=n;i++)
    {
        ll c=1;
        while(n%i==0)
        {
            n/=i;
            c++;
        }
        ans*=c;
    }

    if(n!=1) ans*=2;
    cout<<ans;
}
