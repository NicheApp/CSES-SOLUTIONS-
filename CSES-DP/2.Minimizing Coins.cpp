Problem Link - https://cses.fi/problemset/task/1634
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
ll n,x;
cin>>n>>x;
ll a[n];
for(int i=0;i<n;i++)
cin>>a[i];
vector<ll> dp(x+1,INT_MAX);
dp[0]=0;
for(int i=1;i<=x;i++)
{
for(int j=0;j<n;j++)
{
if(i-a[j]>=0 && i-a[j]!=INT_MAX)
{
dp[i]= min(dp[i],1+dp[i-a[j]]);

}

}
}

if(dp[x]==INT_MAX)
cout<<-1;
else
cout<<dp[x];

return 0;
}
