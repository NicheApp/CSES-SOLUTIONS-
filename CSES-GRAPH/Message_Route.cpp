//Link to Ques- https://cses.fi/problemset/task/1667
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 bool x=false;
void bfs(vector<vector<int>> &graph ,vector<bool> &visited,int start,vector<int> &parent)
{
 
list<int> adj;
visited[start]=true;
adj.push_back(start);
while(!adj.empty()){
 
int s= adj.front();
adj.pop_front();
for(auto it: graph[s])
{
 if(!visited[it]){ 
 parent[it]=s;  
visited[it]=true;
adj.push_back(it);
if(it==parent.size()-1)
{
    x=true;
    return;
}
 }
}
 
}
}
 
void createedge(vector<vector<int>> &graph , int u, int v)
{
graph[u].push_back(v);
graph[v].push_back(u);
 
}
void solve(){
int n,m;
cin>>n>>m;
n++;
vector<vector<int>> graph(n);
vector<int> vt;
for(int i=0;i<m;i++)
{
int a, b;
cin>>a>>b;
 
createedge(graph,a,b);
 
}
vector<bool> visited(n,false);
int count=0;
vector<int> parent(n,0);
bfs(graph,visited,1,parent);
vector<int> ans;
int val=n-1;
if(x==false)
{cout<<"IMPOSSIBLE\n"; return ;}
ans.push_back(val);
 while(val!=1)
 {
val=parent[val];
ans.push_back(val);
 }
 cout<<ans.size()<<endl;
 while(ans.size()>0)
 {
     cout<<ans.back()<<" ";
     ans.pop_back();
 }
 cout<<endl;
return ;
}
int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
 
solve();
 
return 0;
}
