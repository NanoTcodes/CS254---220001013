//longest path in DAG
//enter valid DAG,invalid DAG can be detected using last questions method
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;
void toposort(vector<vector<int>> &g,vector<bool> & vis,vector<int> &indegree,vector<int> & lp){
   
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
        for(int child:g[node]){
            //reduce the indegree of those children as those prerequisites have been visited
            lp[child]=max(lp[child],lp[node]+1);//key updation step
            --indegree[child];
            if(indegree[child]==0){
                q.push(child);
            }
        }
    }
}
int main(){
    int N;//number of vertices,vertice numbering starts from 0 to V-1
    int M;//number of directed edges
    cin>>N>>M;
    vector<int> indegree(N,0);//contains indegree of all vertices
    vector<vector<int>> g(N);//adjacency list
    vector<int> lp(N,0);//will contain the longest path of each node
    for(int i=0;i<M;i++){
        int u,v;//directed edge from u to v
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
    }
    vector<bool> vis(N,false);
    toposort(g,vis,indegree,lp);
    int ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,lp[i]);//iterating over all the longest paths and finding the max
    }
    //if there is a cycle ans non zero edges ,i.e, M is non zero,then answer will be zero,
    if(ans==0&&M!=0){
        cout<<"INVALID DAG"<<endl;
    }else{
        cout<<ans<<endl;
    }
    
    
}

// sample graph used
// 8 8
// 0 1
// 0 3
// 1 2
// 1 5
// 3 4
// 4 6
// 4 7
// 6 7

//output-4

// 3
// 3
// 0 1
// 1 2
// 2 0

// output-INVALID DAG
