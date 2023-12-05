#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second.first
#define th second.second.first
#define fo second.second.second
#define mp make_pair
const ll MOD=1e10;
using namespace std;
vector <pair<ll,pair<ll,pair<ll,ll> > > >ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("NORMA.INP","r",stdin);
    freopen("NORMA.OUT","w",stdout);
    ll n;
    cin>>n;
    ll sum=0;
    //ans.push_back(mp(INT_MAX,mp(INT_MIN,mp(0,0))));
    for(ll i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        ll m=ans.size();
        ans.push_back(mp(a,mp(a,mp(i,i))));
        sum+=a*a;
        for(ll j=m;j>=0;j--)
        {
            if(ans[j].fo!=i-1) continue;
            ll b=min(ans[j].fi,a);
            ll c=max(ans[j].se,a);
            ll cs=ans[j].fo-ans[j].th+2;
            ans.push_back(mp(b,mp(c,mp(ans[j].th,ans[j].fo+1))));
            sum+=b*c*cs;
            //cout<<b<<" "<<c<<" "<<cs<<endl;
            sum%=MOD;
        }
    }
    cout<<sum;

}
