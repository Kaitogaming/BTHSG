#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long n,tong=1;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       tong*=2;
       tong%=1000000007;
   }
   cout<<tong;
}
