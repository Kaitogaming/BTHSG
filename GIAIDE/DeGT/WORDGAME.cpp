#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0,d;
string s,s1;
char a[103][103];
bool check(string a)
{
    ll sz=a.size();
    ll siz=s.size();
    for(ll i=0;sz-i>=siz;i++)
    {
        string b=a.substr(i,siz);
        if(b==s)
        {
            return 1;
        }
    }
    return 0;
}
void solve(ll x,ll y)
{
    if(x==m-1 && y==n-1)
    {
        s1+=a[x][y];
        //cout<<s1<<' ';
        if(check(s1)==1)
        {
            ans++;
        }
        return;
    }
    if(y<n-1)
    {
        s1+=a[x][y];
        solve(x,y+1);
        s1.erase(s1.size()-1);
    }
    if(x<m-1)
    {
        s1+=a[x][y];
        solve(x+1,y);
        s1.erase(s1.size()-1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("WORDGAME.INP","r",stdin);
    freopen("WORDGAME.OUT","w",stdout);
    cin>>m>>n>>d;
    cin>>s;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    solve(0,0);
    cout<<ans%d;
}
