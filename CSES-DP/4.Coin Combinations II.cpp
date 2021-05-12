#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 const unsigned int M = 1000000007;
 
 
void solve(){
ll n,i,j,k,sum;
cin>>n>>sum;
int  a[n];
 
for(i=0;i<n;i++)
cin>>a[i];
   ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        //Fill 1st row with 0 because no amount (except 0) can be formed without any coin
        
        for(i=1;i<=sum;++i)
            dp[0][i] = 0;
        //Fill 1st col by 1 (assuming amount 0 can always be formed)
        for(i=0;i<=n;++i)
            dp[i][0] = 1;
        
        //Fill DP-Table
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=sum;++j)
            {
                if(j>=a[i-1])
                    dp[i][j] = (dp[i][j-a[i-1]]%M+dp[i-1][j]%M)%M;
                else
                    dp[i][j] = dp[i-1][j]%M;
            }
        }
        cout<<dp[n][sum];
    }
 
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t=0;
 
solve();
 
return 0;
}
