#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e6+5;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CENSOR.INP","r",stdin);
    freopen("CENSOR.OUT","w",stdout);
    string s,s1;
    cin>>s>>s1;
    ll n=s.size();
    ll m=s1.size();
    //cout<<n<<" "<<m<<endl;
    for(ll i=0;i<=s.size()-m+1;i++)
    {
        if(s.size()<m || i+m>s.size()) break;
        if(i+m>=s.size()) break;

        string check;
        check=s.substr(i,m);
        //cout<<check<<endl;
        if(check==s1)
        {
            //cout<<check<<" "<<s1<<endl;
            s.erase(s.begin()+i,s.begin()+i+m);
            i-=m;
        }
    }
    //cout<<"cmm"<<endl;
    cout<<s;

}
