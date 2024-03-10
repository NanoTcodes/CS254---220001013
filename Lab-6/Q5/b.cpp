//bridges in a graph

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;

void bridge(int node,vector<vector<int>> &g,vector<bool> &vis,vector<int> &tim,vector<int> &lo,vector<pair<int,int>> &ans,int &cnt,int parent){
    vis[node]=true;
    tim[node]=lo[node]=cnt;
    cnt++;
    for(int child:g[node]){
        if(vis[child]&&child!=parent){
            lo[node]=min(lo[node],lo[child]);
        }else if(vis[child]&&child==parent){
            continue;
        }else{
            bridge(child,g,vis,tim,lo,ans,cnt,node);
            lo[node]=min(lo[node],lo[child]);
        }
        if(lo[child]>tim[node]){//bridge condition,on burning this edge,child should not be able reach a node visited earlier than parent node
            ans.push_back({node,child});
        }
    }
}
int main(){
    int n,m;//vertices and edges
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n,false);
    vector<int> tim(n);//time of first entry in dfs tree
    vector<int> lo(n);//lowest timed node in dfs tree that can be reached from that node
    vector<pair<int,int>> ans;//will contain the bridge edges
    int cnt=0;//stores curr time for tim
    for(int i=0;i<n;i++){//to handle disconnected graphs
        if(vis[i]) continue;
        bridge(i,g,vis,tim,lo,ans,cnt,-1);
    }
    if(ans.size()==0){
        cout<<"no bridges in the graph"<<endl;
    }else{
        for(auto prs:ans){
        cout<<prs.first<<" "<<prs.second<<endl;
    }
    }
}


//ex graph used
// 12
// 14
// 0 1
// 1 2
// 2 3
// 3 0
// 3 4
// 4 5
// 5 6
// 5 8
// 6 7
// 8 7
// 7 9
// 9 10
// 9 11
// 10 11

//output-
// 7 9
// 4 5
// 3 4