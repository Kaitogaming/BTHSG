#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+2;
ll a[N*2];
using namespace std;
map <ll,ll> mp;
ll check=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SELECT.INP","r",stdin);
    freopen("SELECT.OUT","w",stdout);
    ll ans=0;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        char s;
        cin>>s;
        if(s=='+')
        {
            a[i+1]=1;
            check++;
        }else a[i+1]=-1,check--;
        a[i+1]+=a[i];
    }
    mp[0]++;
    for(ll i=1;i<=n;i++)
    {
        ans+=mp[a[i]];
        mp[a[i]]++;
    }
    for(ll i=n+1;i<=n*2;i++)
    {
        a[i]=a[i-1]+(a[i-n]-a[i-n-1]);
    }
    //cout<<ans<<endl;
//    for(ll i=0;i<=n*2;i++)
//    {8
//        cout<<a[i]<< " ";
//    }
    mp[a[n]]--;
    mp[0]--;
    for(ll i=1;i<=n-1;i++)
    {
        mp[a[i]]--;
        ans+=mp[a[i+n]];
        //cout<<ans<<endl;
    }
    cout<<ans;
}
