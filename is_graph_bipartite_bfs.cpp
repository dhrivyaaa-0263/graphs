//Bipartite graph : A graph that can be coloured using 2 colors
//such that no two adjacent nodes have same color

#include <bits/stdc++.h>
using namespace std;
bool checkBipartite(int st,int n,vector<int> adj[],vector<int> &color)
{
    queue<int> q;
    q.push(st);
    color[st] = 1;
    while(!q.empty())
    {
     int node = q.front();
     
     q.pop();
     for(auto it:adj[node])
     {
        if(color[it] == -1)
         {
            color[it] = 1-color[node];
            q.push(it);
            
        }
        else if(color[it] == color[node])
        {
            return false;
        }
     }
    }
  return true;
}
bool isBipartite(int n,vector<int> adj[])
{
     vector<int> color(n+1,-1);
     for(int i=1;i<=n;i++)
     {
         if(color[i] == -1)
         {
             if(!checkBipartite(i,n,adj,color))
             {
                 return false;
             }
         }
     }
     return true ;
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
    if(isBipartite(n,adj))
    {
        cout<<"Graph is bipartite"<<endl;
    }
    else
    {
        cout<<"Not bipartite"<<endl;
    }
    
}
