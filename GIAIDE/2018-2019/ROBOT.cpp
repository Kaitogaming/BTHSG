#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll MAXN=1e5;
using namespace std;
pair <int,int> a[MAXN];
ll n,i,beg=0,ended=0,ans=1;
int main()
{
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    sort(a,a+n);
    beg=a[0].se;
    ended=a[0].se;
    i=1;
    while(i<n)
    {
        if(a[i].fi<ended)
        {
            i++;
        }
        else
        {
            ans++;
            beg=a[i].fi;
            ended=a[i].se;
            i++;
        }
    }
    cout<<ans;
}
