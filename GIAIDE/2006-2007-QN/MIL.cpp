#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
const int N=5e3+5;
using namespace std;
pair<ll,ll> a[N*2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MIL.INP","r",stdin);
    freopen("MIL.OUT","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n*2;i++)
    {
        cin>>a[i].fi;
        if(i%2==0)
        {
            a[i].se=1;
        }else
        {
            a[i].se=-1;
        }
    }
    sort(a,a+n*2);
    ll ans=-1,kq=-1;
    ll beg=0,ed=0;
    ll cnt=0;
    for(ll i=0;i<n*2;i++)
    {
        //cout<<a[i].fi<<" "<<a[i].se<<endl;
        cnt+=a[i].se;
        if(cnt==1 && a[i].se==1)
        {
            kq=max(kq,a[i].fi-ed);
            //cout<<a[i].fi<<" "<<ed<<" "<<kq<<" 11"endl;
            beg=a[i].fi;
        }
        if(cnt==0 && a[i].se==-1)
        {
            ans=max(ans,a[i].fi-beg);
            //cout<<a[i].fi<<" "<<beg<<" "<<ans<<endl;
            ed=a[i].fi;
        }
    }
    //cout<<endl;
    //kq=max(ans,a[n*2-1].fi-beg);
    cout<<ans<<endl<<kq;
}
