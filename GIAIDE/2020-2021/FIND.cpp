#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll i,n,dau,cuoi,curmax,cursum;
pair <int,int> dt[100000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIND.INP","r",stdin);
    freopen("FIND.OUT","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>dt[i].fi>>dt[i].se;
    }
    sort(dt,dt+n);
    dau=dt[0].fi;
    cuoi=dt[0].se;
    curmax=cuoi-dau;
    for(i=1;i<n;i++)
    {
        if(dt[i].fi<=cuoi)
        {
            cuoi=max(cuoi, (ll) dt[i].se);
            cursum=cuoi-dau;
            curmax=max(curmax,cursum);
        }else
        {
            dau=dt[i].fi;
            cuoi=dt[i].se;
            cursum=cuoi-dau;
            curmax=max(curmax,cursum);
        }
    }
    cout<<curmax;
}
