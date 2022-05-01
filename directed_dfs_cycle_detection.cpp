#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfsvis)
{
    visited[node] = 1;
    dfsvis[node] = 1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(detectCycle(it,adj,visited,dfsvis))
            {
                return true;
            }
        }

        else if(dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}
bool isCycle(int n,vector<int> adj[])
{
     vector<int> visited(n+1,0);
     vector<int> dfsvis(n+1,0);
     for(int i=1;i<=n;i++)
     {
         if(!visited[i])
         {
             if(detectCycle(i,adj,visited,dfsvis))
             {
                 return true;
             }
         }
     }
     return false;
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
    if(isCycle(n,adj))
    {
        cout<<"There is cycle present"<<endl;
    }
    else
    {
        cout<<"No Cycle is detected"<<endl;
    }
    
}
