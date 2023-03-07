#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e5+5;
using namespace std;
ll n,t,ans=0,b;
pair <ll,ll> a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        cin>>b;
        ll cs=lower_bound(a,a+n,make_pair(b,(ll) 0))-a;
        if(a[cs].first==b)
        {
            cout<<a[cs].second<<endl;
            ans++;
        }else
        {
            ans--;
            cout<<-1<<endl;
        }
    }
    if(ans<0)
    {
        cout<<-1;
        return 0;
    }
    if(ans>0)
    {
        cout<<1;
        return 0;
    }
    if(ans==0)
    {
        cout<<0;
        return 0;
    }
}
