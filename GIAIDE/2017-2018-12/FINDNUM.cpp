#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FINDNUM.INP","r",stdin);
    freopen("FINDNUM.OUT","w",stdout);
    char s;
    ll sum=0;
    while(cin>>s)
    {
        a[s-'0']++;
        sum+=s-'0';
        //cout<<sum<<endl;
    }
    if(a[0]==0 || sum%3!=0)
    {
        cout<<-1;
        return 0;
    }
    for(ll i=9;i>=0;i--)
    {
        while(a[i]>0)
        {
            cout<<i;
            a[i]--;
        }
    }
}
