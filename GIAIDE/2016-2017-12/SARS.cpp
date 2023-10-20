#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=2e3+55;
using namespace std;
bool check[N];
bool kt[N];
vector <ll> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    check[k]=1;
    ans.push_back(k);
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        for(ll j=0;j<a;j++)
        {
            ll b;
            cin>>b;
            if(check[i+1])
            {
                check[b]=1;
                ans.push_back(b);
            }
        }
    }
    sort(ans.begin(),ans.end());
    //unique(ans.begin(),ans.end());
    ll cnt=0;
    vector<ll> flans;
    for(ll i=0;i<ans.size();i++)
    {
        if(kt[ans[i]]) continue;
        kt[ans[i]]=1;
        flans.push_back(ans[i]);
    }
    cout<<flans.size()<<endl;
    for(ll i=0;i<flans.size();i++)
    {
        cout<<flans[i]<<" ";
    }
}
