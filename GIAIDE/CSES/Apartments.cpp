#include <bits/stdc++.h>
#define ll long long
const int MAXN=2e5+5;
using namespace std;
ll n,m,k,ans=0;
ll a[MAXN];
ll b[MAXN];
int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     cin>>n>>m>>k;
     for(ll i=0;i<n;i++)
     {
         cin>>a[i];
     }
     for(ll i=0;i<m;i++)
     {
         cin>>b[i];
     }
     sort(a,a+n);
     sort(b,b+m);
     ll i=0,j=0;
     while(i<n && j<m)
     {
         if(b[j]>=a[i]-k && b[j]<=a[i]+k)
         {
             j++;
             i++;
             ans++;
         }else if(b[j]<a[i]-k)
         {
             j++;
         }else if(b[j]>a[i]+k)
         {
             i++;
         }
     }
     cout<<ans;
}
