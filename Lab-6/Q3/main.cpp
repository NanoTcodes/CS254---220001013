//strongly connected components

//method-call initial dfs using any start point,then assign post numbers
//post numbers refer to the time at which dfs ends for a particular node(it wont be visited again after this time)
//sort the post[i] numbers corresponding to the nodes in descending order
//reverse all edges,i.e,take transpose of graph
//call dfs on the unvisited vertices in order of post

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;
bool cstm(pair<int,int> x,pair<int,int> y){
    return x.first>=y.first;//sorting in descending order
}
void transpose(vector<vector<int>> &g,vector<vector<int>> &gt){
    int N=g.size();
    for(int i=0;i<N;i++){
        for(int v:g[i]){
            //earlier edge from u to v,now v to u
            gt[v].push_back(i);
        }
    }
}

void post_finding(int node,vector<vector<int>> &g,vector<bool> &vis,vector<int> &post,int &tim){
    vis[node]=true;
    for(auto child:g[node]){
        if(vis[child]) continue;
        post_finding(child,g,vis,post,tim);
    }
    //when you reach the end of dfs for a particular vertex assign time and increment
    post[node]=tim;
    tim++;
}
void strong(int node,vector<int> & curr_comp,vector<bool> &vis,vector<vector<int>> &gt){
    vis[node]=true;
    curr_comp.push_back(node);
    for(auto child:gt[node]){
        if(vis[child]) continue;
        strong(child,curr_comp,vis,gt);
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> post(N);
    vector<bool> vis(N,false);
    vector<vector<int>> g(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int tim=0;//start time for finding post
    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        post_finding(i,g,vis,post,tim);
    }
    for(int i=0;i<N;i++){
        vis[i]=false;//make all nodes unvisited gain for the next step
    }
    //now find transpose 
    vector<vector<int>> gt(N);//gt is transpose graph
    transpose(g,gt);
    //now call dfs in descending order of post
    //map with index first
    vector<pair<int,int>> order(N);
    for(int i=0;i<post.size();i++){
        order[i]={post[i],i};//sort in dec order based on post value
    }
    sort(order.begin(),order.end(),cstm);
    vector<vector<int>> scc;//contains the strongly connected components
    for(auto prs:order){
        int node=prs.second;
        if(vis[node]) continue;
        vector<int> curr_comp;
        strong(node,curr_comp,vis,gt);
        scc.push_back(curr_comp);
    }
    for(auto comp:scc){
        for(auto node:comp){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}

//ex graph used
// 5
// 6
// 0 2
// 2 1
// 1 0
// 2 3
// 3 4
// 4 3

//output,with each strongly connected components seperate by a line
//0 1 2
//3 4

//ex
// 5
// 1
// 0 1
// output
// 4
// 3
// 2
// 0
// 1

//ex
// 6
// 7
// 0 1
// 1 2
// 2 3
// 3 0
// 0 4
// 4 5
// 5 
//output
//0 3 2 1 5 4