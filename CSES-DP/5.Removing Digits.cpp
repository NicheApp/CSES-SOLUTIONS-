#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> finddigits(int n)
{
    vector<int> alldigits;
while(n!=0)
{
    if(n%10!=0)
alldigits.push_back(n%10);
n=n/10;
 
}
return alldigits;
}
 
int dpsol(int n,vector<int> &dp)
{
if(n==0)
return 0;
if(dp[n]!=-1)
return dp[n];
int ans=INT_MAX;
vector<int> a=finddigits(n);
 
for(auto it: a){
int subans=0;
if(n-it>=0){
   
subans=dpsol(n-it,dp);
 
if(subans!=INT_MAX && 1+subans<ans)
{
 
ans=1+subans;
}
 
}
 
}
 
return dp[n]= ans;
}
 
 
void solve(){
ll n,i,j,k;
cin>>n;
vector<int> dp(n+1,-1);
cout<<dpsol(n,dp);
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t=0;
 
solve();
 
return 0;
}
