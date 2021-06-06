    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    
    void dijikstra(vector<vector<pair<ll,ll>>> &graph,ll n)
    {
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,LONG_LONG_MAX);
        vector<bool> visited(n,false);
        dist[1]=0;
        pq.push({0,1});
    
    
    while(!pq.empty())
    {
    ll u =pq.top().second;
    pq.pop();
    
    if(visited[u]) continue;
    
    visited[u]=true;
    
    for(auto it: graph[u]){
        if(!visited[it.first]){
    ll v= it.first;
    ll w= it.second;
    if( dist[u]+w <dist[v])
    {
    dist[v]=dist[u]+w;
    pq.push({dist[v],it.first});
    
    }
        }
    
    }
    
    }
    
    for(ll i=1;i<n;i++)
        {
            cout<<dist[i]<<" ";
        }
    
    }
    
    void createedge(vector<vector<pair<ll,ll>>> &graph,ll a, ll b ,ll w){
    
    graph[a].push_back({b,w});

    
    }
    int main(){
    ll n, m;
    cin>>n>>m;
    n++;
    vector<vector<pair<ll,ll>>> graph(n);
    for(int i=0;i<m;i++)
    {
    ll a,b,w;
    cin>>a>>b>>w;
    createedge(graph,a,b,w);
    }
    
    dijikstra(graph,n);
    
    return 0;
    }
