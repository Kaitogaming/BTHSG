#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+2;
bool snt[N];
using namespace std;
void sang()
{
    snt[1]=0;
    snt[0]=0;
    for(ll i=2;i<N;i++)
    {
        for(ll j=i+i;j<N;j+=i)
        {
            snt[j]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("GOLDBACH.INP","r",stdin);
    freopen("GOLDBACH.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    ll n;
    cin>>n;
    sang();
    for(ll i=n/2;i>=2;i--)
    {
        if(!snt[i]) continue;
        ll a=n-i;
        if(snt[a])
        {
            cout<<i<<" "<<a;
            return 0;
        }
    }
}
