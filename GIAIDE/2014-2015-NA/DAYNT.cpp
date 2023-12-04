#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=32e3+5;
using namespace std;
bool snt[N];
bool check[N];
void first()
{
    memset(snt,1,sizeof(snt));
    snt[0]=0;
    snt[1]=0;
    for(ll i=2; i<=N; i++)
    {
        if(snt[i])
            for(ll j=i+i; j<=N; j+=i)
            {
                snt[j]=0;
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("DAYNT.INP","r",stdin);
    freopen("DAYNT.OUT","w",stdout);
    ll k;
    cin>>k;
    first();
    ll a;
    set<ll> ans;
    //vector <ll> ans;
    while(cin>>a)
    {
        if(snt[a]==0) continue;
        if(check[a]) continue;
        check[a]=1;
        ans.insert(a);
    }
    //sort(ans.begin(),ans.end());
    set<ll>::iterator it;
    ll cnt=0;
    for(it=ans.begin();it!=ans.end();it++)
    {
        cnt++;
        cout<<*it<<" ";
        if(cnt==k)
        {
            break;
        }
    }
}
