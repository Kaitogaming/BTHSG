#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
bool snt[N];
void first()
{
    snt[1]=0;
    snt[0]=0;
    for(ll i=2;i<=N;i++)
    {
        if(snt[i])
            for(ll j=i+i;j<=N;j+=i)
        {
            snt[j]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    memset(snt,1,sizeof(snt));
    ll n;
    cin>>n;
    first();
    for(ll i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            snt[i]=1;
        }
    }
    for(ll i=n;i>0;i--)
    {
        if(snt[i])
        {
            cout<<i<<" ";
        }
    }
}
