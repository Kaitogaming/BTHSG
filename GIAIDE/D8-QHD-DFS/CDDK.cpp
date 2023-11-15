#include <bits/stdc++.h>
#define N 100002
using namespace std;
vector <int> a[N];
int n,i,u,v,kt,sl[N],d[N],ts[N],kq[N],j,dd[N],cnt;
void dfs(int u,int p)
{
 sl[u]=1;
 for(int i=0;i<a[u].size();i++)
 {
 int v=a[u][i];
 if(v==p) continue;
 dfs(v,u);
 sl[u]+=sl[v];
 }
}
void DFS(int u,int p,int k)
{
 cnt++;
 int luu=cnt;
 for(int i=0;i<a[u].size();i++)
 {
 int v=a[u][i];
 if(v==p) continue;
 DFS(v,u,k);
 if(kt==0) return;
 }
 int dem=0;
 for(int i=0;i<a[u].size();i++)
 {
 int v=a[u][i];
 if(v==p) continue;
 int x=sl[v]%k;
 if(d[x]!=luu)
 {
 d[x]=luu; ts[x]=0;
 }
 if(x==0) continue;
 if(d[k-x]==luu && ts[k-x]>0)
 {
 ts[k-x]--; dem--;
 }
 else
 {
 dem++;
 ts[x]++;
 }
 }
 if(dem>1)
 {
 kt=0;
 }
}
void xuly1()
{
 dfs(1,0);
 for(i=n-1;i>=1;i--)
 {
 if((n-1)%i>0) continue;
 for(j=2*i;j<n;j+=i)
 if(kq[j]==1) { kq[i]=1; break; }
 if(kq[i]==1) continue;
 kt=1;
 DFS(1,0,i);
 kq[i]=kt;
 }
}
int main()
{
// freopen("ntu.inp","r",stdin);
// freopen("ntu.out","w",stdout);
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 cin>>n;
 for(i=1;i<n;i++)
 {
 cin>>u>>v;
 a[u].push_back(v); a[v].push_back(u);
 }
 xuly1();
 for(i=1;i<n;i++)
 {
 if(kq[i]==1) putchar('1');
 else putchar('0');
 }
}
