#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,a,beg=0,end,sothuyen=0,i;
    int p[200000];
    cin>>n>>x;
    end=n-1;
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    sort(p,p+n);
    while(beg<=end)
    {
    if((p[beg]+p[end])>x)
    {
        sothuyen+=1;
        end-=1;
    }else
    {
        sothuyen+=1;
        beg+=1;
        end-=1;
    }
    }
    cout<<sothuyen;

}
