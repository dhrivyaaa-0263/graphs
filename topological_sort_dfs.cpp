#include <bits/stdc++.h>
using namespace std;
void  topological_sort(int node,vector<int> adj[],vector<int> &visited,stack<int> &st)
{
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
             topological_sort(it,adj,visited,st);
            
        }

       
    }
    st.push(node);
}
vector<int> helper(int n,vector<int> adj[])
{
     vector<int> visited(n+1,0);
      stack<int> st;
     for(int i=1;i<=n;i++)
     {
         if(!visited[i])
         {
             topological_sort(i,adj,visited,st);
           
         }
     }
     vector<int> ans;
     while(!st.empty())
     {
         ans.push_back(st.top());
         st.pop();
     }
     return ans;
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
    vector<int> res = helper(n,adj);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    
}
