#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0,s,n,i;
ll a[5000];
void solve(int id,int curs)
{
    if(id==n)
    {
        if(curs==s)
        {
            ans++;
        }
        return;
    }
    solve(id+1,curs);
    solve(id+1,curs+a[id]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FAIR.INP","r",stdin);
    freopen("FAIR.OUT","w",stdout);
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve(0,0);
    cout<<ans;
}
