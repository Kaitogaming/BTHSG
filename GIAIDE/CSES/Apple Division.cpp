#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,sum,ans=1000000000,check;
ll a[24];
void solve(int id,ll cur)
{
    if(id==n)
    {
        ll r=sum-cur;
        ll check=abs(cur-r);
        ans=min(ans,check);
        return;
    }
    solve(id+1,cur+a[id]);
    solve(id+1,cur);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("applediv.inp","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    solve(0,0);
    cout<<ans;
    /*chiến*/
}
