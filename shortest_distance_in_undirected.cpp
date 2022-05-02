//shortest path from source to all other nodes
//done by using breadth first search
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
    vector<int> adj[n+1];
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfs(n,adj,1);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<"->";
    }
}
