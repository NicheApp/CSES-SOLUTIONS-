#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int n,i,j,k,x;
cin>>n>>x;
int price[n+1],pages[n+1];
for(i=1;i<=n;i++)
cin>>price[i];
for(i=1;i<=n;i++)
cin>>pages[i];
vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
 
for(int i=1;i<=n;i++)
{
 
for(int j=1;j<=x;j++)
{
 
if(j-price[i]>=0 )
{
 
  dp[i][j]= max(pages[i]+dp[i-1][j-price[i]],dp[i-1][j]);
 
}
else
{
dp[i][j]=dp[i-1][j];
 
 
}
 
}
}
 
 
cout<<dp[n][x];
 
return 0;
}
