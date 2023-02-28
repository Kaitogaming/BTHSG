#include <bits/stdc++.h>
#define ll long long
using namespace std;
int kt[10000];
ll i,n,ans=0,kq,a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SMM.INP","r",stdin);
    freopen("SMM.OUT","w",stdout);
    memset(kt,0,sizeof(kt));
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        kt[a]+=1;
        if(kt[a]>1)
        {
            ans+=1;
        }
    }
    cout<<ans<<endl;
    for(i=0;i<10000;i++)
    {
        if(kt[i]>1)
        {
            cout<<i<<endl;
            kq=kt[i];
        }
    }
    cout<<kq;


}
