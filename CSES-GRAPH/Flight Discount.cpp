#include<bits/stdc++.h>
#define inf 1e17;
using namespace std;
typedef long long ll;

struct e
{

ll u,v,w;
};

void dijikstra(vector<vector<pair<ll,ll>>> &graph, ll src,ll n,vector<ll> &dist){

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
pq.push({0,src});
dist[src]=0;
vector<bool>visited(n,false);
while(!pq.empty()){

ll u =pq.top().second;
    pq.pop();
if(visited[u]) continue;

visited[u]=true;


for(auto it: graph[u])
{
    ll v= it.first;
    ll w= it.second;
if(!visited[v])
{
if( dist[u]!=LONG_LONG_MAX && dist[u]+w<dist[v])
{

    dist[v]=dist[u]+w;
    pq.push({dist[v],v});
}


}

}

}


}

int main()
{
std::ios::sync_with_stdio(false);
cin.tie(NULL);
ll n,m;
cin>>n>>m;

vector<vector<pair<ll,ll>>>graph1(n+1);
vector<vector<pair<ll,ll>>>graph2(n+1);
vector<e>tp;
ll a,b,w;
for(ll i=0;i<m;i++){

cin>>a>>b>>w;
tp.push_back({a,b,w});
graph1[a].push_back({b,w});
graph2[b].push_back({a,w});

}
vector<ll>dist1(n+1,LONG_LONG_MAX);
vector<ll>dist2(n+1,LONG_LONG_MAX);
dijikstra(graph1,1,n+1,dist1);
dijikstra(graph2,n,n+1,dist2);

ll ans=LONG_LONG_MAX;

for(auto it: tp)
{
ans= min(ans,dist1[it.u]+dist2[it.v]+(it.w)/2);

}


cout<<ans<<endl;


return 0;
}
