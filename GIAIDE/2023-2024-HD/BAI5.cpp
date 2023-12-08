#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
//    freopen("BAI5.INP","r",stdin);
//    freopen("BAI5.OUT","w",stdout);
    ll n;
    cin>>n;
    pair<ll,ll> cur=make_pair(0,0);
    ll mx=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(a>cur.second)
        {
            cur.first+=b;
            cur.second=a;
            mx=max(mx,cur.first);
        }else
        {
            cur.second=a;
            mx=max(mx,cur.first);
            cur.first=b;
        }
        //cout<<mx<<" "<<cur.first<<" "<<cur.second<<endl;
    }
    cout<<mx;
}
