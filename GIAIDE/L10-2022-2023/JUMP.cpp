#include <bits/stdc++.h>
#define ll long long
const int MAXN=2e5+5;
using namespace std;
ll n,m,ans=0;
ll a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("JUMP.INP","r",stdin);
    freopen("JUMP.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll i=0,j=n-1;
    while(i<=j)
    {
        if(a[i]+a[j]<=m)
        {
            ans++;
            i++;
            j--;
        }else
        {
            j--;
            ans++;
        }
    }
    cout<<ans;
}
