#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int V, vector<vector<int>>&adj, bool visited[],vector<int>&pre,vector<int>&post,int u,int &time){
	    pre[u]=time;
	    visited[u]=true;
	    time++;
	    for(int i:adj[u]){
	        if(!visited[i]){
	            dfs(V,adj,visited,pre,post,i,time);
	        }
	    }
	    post[u]=time;
	    time++;
	}
	
	void findpreandpost(int V, vector<vector<int>>& adj,vector<int>&pre,vector<int>&post){
	    int time=0;
	    bool visited[V];
	    for(int i=0;i<V;i++){
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(V,adj,visited,pre,post,i,time);
	        }
	    }
	    
	    
	}
	
	void dfsregular(int V, vector<vector<int>>&adj, bool visited[],int u){
	    visited[u]=true;
	    for(int i:adj[u]){
	        if(!visited[i])dfsregular(V,adj,visited,i);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>pre(V);
        vector<int>post(V);
        findpreandpost(V,adj,pre,post);
        pair<int,int> p[V];
        for(int i=0;i<V;i++){
            p[i]={post[i],i};
        }
        sort(p,p+V, greater<pair<int, int>>());
        vector<vector<int>> revadj(V);
        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                revadj[j].push_back(i);
            }
        }
        bool visited[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int ans=0;
        for(int i=0;i<V;i++){
            int v=p[i].second;
            if(!visited[v]){
                dfsregular(V,revadj,visited,v);
                ans++;
            }
        }
        return ans;
        
        
        
    }
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

