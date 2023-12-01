#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=3e2+5;
using namespace std;
ll dp[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("STEDIT.INP","r",stdin);
//    freopen("STEDIT.OUT","w",stdout);
    string s,s1;
    cin>>s>>s1;
    //cout<<s<<" "<<s1<<endl;
    ll n=s.size();
    ll m=s1.size();
    s=" "+s;
    s1=" "+s1;
    for(ll i=1;i<=max(n,m);i++)
    {
        dp[i][0]=i;
        dp[0][i]=i;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j]+1;
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            if(s[i]==s1[j])
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
                if(s[i]==s1[j+1] && s[i+1]==s1[j])
                {
                    dp[i][j]=min(dp[i][j],dp[i-2][j-2]+1);
                }
        }
    }
    cout<<dp[n][m]<<endl;
    ll i=1,j=1;
    while(i<=n || j<=m)
    {
        if(dp[i][j]==dp[i-1][j]+1)
        {
             cout<<4<<" "<<i<<endl;
             i++;
             j++;
        }else if(dp[i][j]==dp[i][j-1]+1)
        {
            cout<<3<<" "<<i<<" "<<s1[j]<<endl;
            i++;
            j++;
        }else if(i>1 && j>1 && s[i]==s1[j+1] && s[i+1]==s1[j] && dp[i][j]==dp[i-2][j-2]+1)
        {
             cout<<2<<" "<<i<<" "<<i+1<<endl;
             i+=2;
             j+=2;
        }else if(dp[i][j]==dp[i-1][j-1]+1)
        {
            cout<<1<<" "<<i<<" "<<s1[i]<<endl;
            i++;
            j++;
        }else
        {
            i++;
            j++;
        }
    }

}
