#include<bits/stdc++.h>
#define na "8/"
using namespace std;
int n,k,a[100001];
bool b[100001];
void c1()
{
    long long res =0;
    int t =0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]>0)
        {
            res+=a[i];
            t = a[i];
            a[i]=0;
            for (int j=i+1; j<=n; j++)
                if (a[j]>0 && a[j]<=t-k)
                {
                    t=a[j];
                    a[j]=0;
                }
        }
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bai3.inp","r",stdin);
    freopen("bai3.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    c1();
}
