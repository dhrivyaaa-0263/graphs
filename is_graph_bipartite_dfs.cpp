//Bipartite graph : A graph that can be coloured using 2 colors
//such that no two adjacent nodes have same color

#include <bits/stdc++.h>
using namespace std;
bool checkBipartite(int node,vector<int> adj[],vector<int> &color)
{
    
    for(auto it:adj[node])
    {
        if(color[it] == -1)
        {   color[it] = 1-color[node];
            if(!checkBipartite(it,adj,color))
            {
                return false ;
            }
        }

        else if(color[it] == color[node])
        {
            return false;
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
             if(!checkBipartite(i,adj,color))
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
