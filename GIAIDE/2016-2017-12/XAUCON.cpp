#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e5+5;
using namespace std;
bool check[27];
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XAUCON.INP","r",stdin);
    freopen("XAUCON.OUT","w",stdout);
    ll vtans=INT_MIN,ans=INT_MIN;
    string s;
    cin>>s;
    ll n=s.size();
    for(ll i=0;i<n;i++)
    {
        a[i]=s[i]-'A';
    }
//    for(ll i=0;i<n;i++)
//    {
//        cout<<a[i];
//        //a[i]=s[i]-'A';
//    }
//    cout<<endl;
    ll i=0,j=1;
    check[a[0]]=1;
    //BBGABBABCDEACCDB
    while(j<n)
    {
        if(check[a[j]])
        {
            while(a[i]!=a[j])
            {
                check[a[i]]=0;
                i++;
            }
            i++;
        }else
        {
            check[a[j]]=1;
            if(j-i+1>ans)
            {
                ans=j-i+1;
                vtans=i+1;
            }
        }
        j++;
    }
    cout<<vtans<<" "<<ans;
}
