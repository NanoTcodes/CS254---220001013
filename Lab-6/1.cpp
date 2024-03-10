#include<bits/stdc++.h>
using namespace std;

vector<int> topsort(vector<int>adj[],vector<int>indegree,int v){
    //bool visited[v];
    vector<int>top{};
    // for(bool vis:visited){
    //     vis=false;
    // }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        top.push_back(u);
        q.pop();
        //visited[u]=true;
        for(int i:adj[u]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }

    }
    if(top.size()!=v){
        vector<int> newv(v,-1);
        return newv;
    }
    return top;
}


int main(){
    int v=6;
    vector<int>adj[v];
    int e=8;
    vector<int>indegree(v,0);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    vector<int>ans=topsort(adj,indegree,v);
    for(int i=0;i<v;i++){
        cout<<ans[i]<<" ";
    }

return 0;}