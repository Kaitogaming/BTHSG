#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,i;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DKGDN.INP","r",stdin);
    freopen("DKGDN.OUT","w",stdout);
    ll curmax,maxd,curcs=0,csmax;
    cin>>n;
    cin>>a;
    b=a;
    curmax=1;
    maxd=1;
    for(i=1;i<n;i++)
    {
        cin>>a;
        if(a>=b)
        {
            curmax+=1;
            if(curmax>maxd)
            {
                csmax=curcs;
                maxd=curmax;
            }
        }else
        {
            curcs=i;
            curmax=1;
        }
        b=a;
    }
    cout<<csmax+1<<' '<<maxd;
}
