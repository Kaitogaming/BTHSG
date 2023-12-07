#include <bits/stdc++.h>
using namespace std;
long long s[100001], f[100001], res=0, sum;
int a[100001],n;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bai5.inp","r",stdin);
    freopen("bai5.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        sum+=a[i];
    }
//sub1();
    for (int i=1; i<=n; i++)
    {
        f[i]=s[i];
        if (i>=10)
        {
            int m = INT_MAX;
            for (int j=i; j>i-10; j--)
            {
                m = min(a[j],m);
                f[i]=min(f[i],f[j-1]+s[i]-s[j-1]);
            }
            f[i] = min (f[i],f[i-10]+s[i]-s[i-10]-m);
        }
    }
    cout<<f[n];
    return 0;
}
