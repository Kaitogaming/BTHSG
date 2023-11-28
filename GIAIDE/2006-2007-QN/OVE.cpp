#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second.first
#define th second.second
#define mp make_pair
using namespace std;
string s[250];
ll move1[4]={0,0,1,-1};
ll move2[4]={1,-1,0,0};
bool a[250][250];
ll n,m;
bool check(ll x,ll y)
{
    return x>=0 && x<=n*2 && y>=0 && y<=m*2 && a[x][y]==0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("OVE.INP","r",stdin);
    freopen("OVE.OUT","w",stdout);
    cin>>m>>n;
    string s1;
    getline(cin,s1);
    queue<pair<ll,pair<ll,ll>>> q;
    ll i=0;
    while(getline(cin,s[i]))
    {
        while(s[i].size()<=m*2)s[i]+=" ";
        //cout<<s[i]<<" "<<i<<endl;
        for(ll j=0; j<s[i].size(); j++)
        {
            if(s[i][j]!=' ')
            {
                a[i][j]=1;
            }else if((i==0 || i==n*2)&& s[i][j]==' ')
            {
                q.push(mp(i,mp(j,1)));
                //cout<<i<<" "<<j<<" dcm"<<endl;
            }else if(j==0 || j==s[i].size()-1)
            {
                q.push(mp(i,mp(j,1)));
                //cout<<i<<" "<<j<<" dcm"<<endl;
            }
        }
        i++;
    }
    ll kq=-1;
//    for(ll i=0;i<=n*2;i++)
//    {
//        for(ll j=0;j<=m*2;j++)
//        {
//            if(a[i][j])
//            {
//                cout<<1;
//            }else cout<<0;
//        }
//        cout<<endl;
//    }
    while(q.size())
    {
        pair<ll,pair<ll,ll>> b=q.front();
        ll x=b.fi;
        ll y=b.se;
        ll c=b.th;
        a[x][y]=1;
        q.pop();
        kq=max(kq,c);
        for(ll i=0;i<4;i++)
        {
            ll x1=x+move1[i];
            ll y1=y+move2[i];
            if(check(x1,y1)==0) continue;
            a[x1][y1]=1;
            q.push(mp(x1,mp(y1,c+1)));
            //cout<<x1<<" "<<y1<<" "<<c+1<<endl;
            kq=max(kq,c+1);
        }
    }
    cout<<kq/2;
}
