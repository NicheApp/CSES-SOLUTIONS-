#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dpsol(vector<vector<char>> &grid, int i, int j,int n,vector<vector<int>> &dp)
{
if(grid[i][j]=='.' && i==n-1 && j==n-1)
{
return 1;
}
 
 
int ans=0;
 
if(grid[i][j]=='.')
{
     if( dp[i][j]!=-1)
      return dp[i][j]%1000000007;
if(i+1<n && grid[i+1][j]=='.')
{
    
    ans=(ans%1000000007+dpsol(grid,i+1,j,n,dp)%1000000007)%1000000007;
}
if(j+1<n && grid[i][j+1]=='.')
{
    ans=(ans%1000000007+dpsol(grid,i,j+1,n,dp)%1000000007);
}
 
 
 
}
 
return dp[i][j]=ans%1000000007;
}
void solve(){
int n,i,j,k;
cin>>n;
vector<vector<char>> a(n,vector<char>(n));
for(i=0;i<n;i++){
for(int j=0;j<n;j++)
{
 
cin>>a[i][j];
 
}
 
}
vector<vector<int>> dp(n,vector<int>(n,-1));
 
cout<<dpsol(a,0,0,n,dp);
 
return ;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t=1;
//cin>>t;
//while(t--)
//{
solve();
//}
return 0;
}
