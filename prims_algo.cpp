#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
        adj[v].push_back({u,wt});
	}
    vector<int> key(n,INT_MAX);
    vector<int> parent(n,-1);
    vector<bool> mst(n,false);
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});   //{key[i],i} key[i] is the minimal value we need to find , and i is the index
    for(int count = 0;count<n-1;count++)
    {  

        //this part is optimised using min heap i.e. priority queue
       /* int mini = INT_MAX;
        int u;
        for(int v = 0;v<n;v++)
        {
            if(mst[v] == false and key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }*/
       int u = pq.top().second;
       pq.pop();
        mst[u] = true;

        for(auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false and  weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }

        }
    }
	
	for(int i=1;i<n;i++)
    {
        cout<<parent[i] <<"->"<<i<<endl;
    }

	return 0; 
} 


