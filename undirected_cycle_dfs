#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int node,int par,vector<int> adj[],vector<int> &visited)
{
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(detectCycle(it,node,adj,visited))
            {
                return true;
            }
        }

        else if(it != par)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int n,vector<int> adj[])
{
     vector<int> visited(n+1,0);
     for(int i=1;i<=n;i++)
     {
         if(!visited[i])
         {
             if(detectCycle(i,-1,adj,visited))
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
        adj[v].push_back(u);
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
