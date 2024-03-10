//cycle in directed graph
//using topological sort method
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;
void toposort(vector<vector<int>> &g,vector<int> &ans,vector<bool> & vis,vector<int> &indegree){
    
    int V=indegree.size();
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        vis[node]=true;
        ans.push_back(node);
        for(int child:g[node]){
            
            --indegree[child];
            if(indegree[child]==0){
                q.push(child);
            }
        }
    }
}
int main(){
    int V;//number of vertices,vertice numbering starts from 0 to V-1
    int E;//number of directed edges
    cin>>V>>E;
    vector<int> indegree(V,0);//contains indegree of all vertices
    vector<vector<int>> g(V);//adjacency list
    for(int i=0;i<E;i++){
        int u,v;//directed edge from u to v
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
    }
    vector<bool> vis(V,false);
    vector<int> ans;//contains the topological sorting
    toposort(g,ans,vis,indegree);//disconnected components can be handled using vis array by calling it multiple times
    if(ans.size()!=V){
        cout<<"contains a loop"<<endl;
    }else{
       cout<<"doesnt contain a loop"<<endl;
    }
}

//sample graph used
// 8 8
// 0 1
// 0 3
// 1 2
// 1 5
// 3 4
// 4 6
// 4 7
// 6 7
//output -doesnt contain a loop

// 3 3
// 0 1
// 1 2
// 2 0

//output- contains a loop

