#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> adj[],vector<int> &visited,vector<int> &d)
{
    d.push_back(node);
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it,adj,visited,d);
        }
    }    
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
    vector<int> d;
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,d);
        }
    }
    for(auto it:d)
    {
        cout<<it<<"->";
    }
}
