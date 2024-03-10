//articulation point
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll=long long;

void bridge(int node,vector<vector<int>> &g,vector<bool> &vis,vector<int> &tim,vector<int> &lo,vector<int> &ans,int &cnt,int parent){
    vis[node]=true;
    tim[node]=lo[node]=cnt;
    cnt++;
    int children=0;
    for(int child:g[node]){
        if(vis[child]&&child!=parent){
            lo[node]=min(lo[node],tim[child]);
        }else if(vis[child]&&child==parent){
            continue;
        }else{
            children++;
            bridge(child,g,vis,tim,lo,ans,cnt,node);
            lo[node]=min(lo[node],lo[child]);
        }
        if(lo[child]>=tim[node]&&parent!=-1){//articulation point condition,on burning this point,child should not be able reach a node visited earlier than parent node
            ans.push_back(node);
        }
        if(parent==-1&&children>1){
            ans.push_back(node);
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
    vector<int> ans;//will contain the articulation points
    int cnt=0;//stores curr time for tim
    for(int i=0;i<n;i++){//to handle disconnected graphs
        if(vis[i]) continue;
        bridge(i,g,vis,tim,lo,ans,cnt,-1);
    }
    if(ans.size()==0){
        cout<<"no articulation points"<<endl;
    }else{
    set<int> s;
    //ans can have repeating values
    for(int i=0;i<ans.size();i++){
        s.insert(ans[i]);
    }
    for(int val:s){
        cout<<val<<" ";
    }
    cout<<endl;
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
// 3 4 5 7 9