#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int N=1e2+5;
using namespace std;
    ll k=1;
    ll n,m;
    ll t[N*N*2];
    ll cal(ll x,ll y)
    {
        return x*m+y;
    }
    void update(ll id,ll v)
    {
        for(t[id+=k]=v;id>1;id>>=1)
        {
         t[id>>1]=max(t[id],t[id^1]);
         //cout<<id<<endl;
        }
    }
    ll get(ll l,ll r)
    {
        ll ans=0;
        for(l+=k,r+=k;l<r;l>>=1,r>>=1)
        {
              if(l&1) ans=max(ans,t[l++]);
             if(r&1) ans=max(ans,t[--r]);
        }
        return ans;
    }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    ll cnt=0;
    cin>>n>>m;
    while(k<n*m)
    {
        k*=2;
    }
    //cout<<k<<endl;
    for(ll i=k;i<k+n*m;i++)
    {
        cin>>t[i];
        if(t[i]) cnt++;
    }
  //  cout<<cnt<<endl;
    for(ll i=k-1;i>=1;i--)
    {
        t[i]=max(t[i<<1],t[i<<1|1]);
    }
    vector <string> ans;
    while(cnt>0)
    {
        string kq;
        ll i=0,j=0;
        //cout<<i<<" "<<j<<endl;
        while(i<n || j<m)
        {
            if(i==n-1 && j==m-1) break;
            //cout<<i<<" "<<j<<endl;

            if(j<m && (get(cal(i,j+1),cal(i,m))|| i==n-1))
            {
                kq+='R';
                //cout<<i<<" "<<j<<endl;
                if(t[cal(i,j)+k])
                {
                 //  cout<<t[cal(i,j)+k]<<" "<<cal(i,j)+k<<" "<<i<<" "<<j<<" ";
                    update(cal(i,j),0);
                    cnt--;
                    //cout<<" dcm"<<t[cal(i,j)+k]<<endl;
                }
                j++;
            }else
            {
                kq+='D';
                if(t[cal(i,j)+k])
                {
                    //cout<<t[cal(i,j)]<<" "<<cnt<<" ";
                    update(cal(i,j),0);
                    cnt--;
                    //cout<<i<<" "<<j<<" "<<t[cal(i,j)]<<endl;
                }
                i++;
            }
            //cout<<i<<" "<<j<<endl;
        }
        ans.push_back(kq);
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
