//1: Calculate indegree of every node
//2:check if a nodes indegree is 0,insert it in a queue
//3:now apply regular bfs

#include <bits/stdc++.h>
using namespace std;
vector<int> topobfs(int n,vector<int> adj[])
{ 
    queue<int> q;
    vector<int> ind(n+1,0);
   // ind[0] = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            ind[it]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(ind[i] == 0)
        {
            q.push(i);
        }
    }
     vector<int> topo;
    while(!q.empty())
    {
     int node = q.front();
     q.pop();
     topo.push_back(node);
     for(auto it:adj[node])
     {
        ind[it]--;
        if(ind[it] == 0)
        {
            q.push(it);
        }
     }
    }
  return topo;
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
       
    }
    vector<int> ans = topobfs(n,adj);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    
}
