#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    freopen("DLCD.INP","r",stdin);
    freopen("DLCD.OUT","w",stdout);
    ll a,b;
    while(cin>>s)
    {

        ll ans=0,sum=0;
        for(ll i=0;i<4;i++)
        {
            sum*=10;
            sum+=s[i]-'0';
        }
        while(sum!=0 && sum!=6174)
        {
            //cout<<sum<<endl<<endl;
            a=0;
            b=0;
        sort(s.begin(),s.end());
        for(ll i=0;i<4;i++)
        {
            a*=10;
            a+=s[i]-'0';
            b*=10;
            b+=s[3-i]-'0';
        }
       // cout<<a<<endl<<b<<endl;
        sum=b-a;
        //cout<<sum<<endl;
        string s1="0000";
        ll c=sum;
        ll i=0;
        while(c)
        {
            s1[i]=c%10+'0';
            c/=10;
            i++;
        }
        //cout<<s1<<endl;
        s=s1;
        ans++;
        //if(ans==10) return 0;
        }
        cout<<ans<<endl;
        //break;
    }
}
