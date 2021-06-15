#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
ll n,i,j,k,x;
cin>>n;
set<ll> st;
for(i=0;i<n;i++)
{cin>>x;st.insert(x);}
cout<<st.size();
return ;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);

solve();

return 0;
}
