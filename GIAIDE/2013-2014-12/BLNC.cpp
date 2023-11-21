#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
    ll n,k;
void solve1()
{
    cout<<n<<endl;
    for(ll i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
}
void solve2()
{
    cout<<n*(n-1)<<endl;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j) continue;
            cout<<i<<" "<<j<<endl;
        }
    }
}
void solve3()
{
    cout<<n*(n-1)*(n-2)<<endl;
     for(ll i=1;i<=n;i++)
     {
         for(ll j=1;j<=n;j++)
         {
             for(ll k=1;k<=n;k++)
             {
                 if(i==j || i==k || j==k) continue;
                 cout<<i<<" "<<j<<" "<<k<<endl;

             }
         }
     }
}
void solve4()
{
    cout<<n*(n-1)*(n-2)*(n-3)<<endl;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i!=j)
            for(ll k=1;k<=n;k++)
            {
                if(i!=k && j!=k)
                    for(ll z=1;z<=n;z++)
                {
                    if(i==z || j==z || k==z) continue;
                    cout<<i<<" "<<j<<" "<<k<<" "<<z<<endl;
                }
            }
        }
    }
}

void solve5()
{
    cout<<n*(n-1)*(n-2)*(n-3)*(n-4);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j) continue;
            for(ll k=1;k<=n;k++)
            {
                if(i==k || j==k) continue;
                for(ll z=1;z<=n;z++)
                {
                    if(i==z || j==z || k==z) continue;
                    for(ll f=1;f<=n;f++)
                    {
                        if(i==f || j==f || k==f || z==f) continue;
                        cout<<i<<" "<<j<<" "<<k<<" "<<z<<" "<<f<<endl;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BLCN.INP","r",stdin);
    freopen("BLCN.OUT","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        solve1();
    }else if(k==2)
    {
        solve2();
    }else if(k==3)
    {
        solve3();
    }else if(k==4)
    {
        solve4();
    }else if(k==5)
    {
        solve5();
    }
}
