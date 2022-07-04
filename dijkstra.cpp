#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int n,vector<int> adj[],int src)
{
     vector<int> dis(n+1,INT_MAX);
     
   
     queue<int> q;
     q.push(src);
     dis[src] = 0;
     while(!q.empty())
     {
        int node = q.front();
        q.pop();
       
        for(auto it:adj[node])
        {
            if(dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
     }
         
     
     return dis;
}
int main() {
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> adj[n+1];
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
  int source;
  cin>>source;
  visited<int> dis_vec(n+1,INT_MAX);
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;  //dist,node
  dis_vec[src] = 0;
  pq.push({0,src});
  while(!pq.empty())
  {
    int dist = pq.front().first;
    int node = pq.front().second;
    pq.pop();
    for(auto it:adj[node])
    {
      int curr = it.first;
      int d = it.second;
      if(d + dist < dis_vec[curr])
      {
        dis_vec[curr]  = d + dist;
        pq.push({dis_vec[curr],curr});
      }
    }
  }
  cout<<"distance from source"<<src<<", are : "<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<dis_vec[i]<<endl;
  }
}
