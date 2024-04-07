#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool vis[N];
int ind[N];

void topological_sort(){
    queue<int> q;
    for(int i=0; i<V; i++){
        if(!ind[i]){
            q.push(i);
            vis[i] = 1;
        }
    }
    while(!q.empty()){
        int c = q.front(); q.pop();
        cout << c << " ";
        for(auto x:adj[c]){
            ind[x]--;
            if(!ind[x] && !vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            vis[i] = 0;
            ind[i] = 0;
        }
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            ind[v]++;
        }
        topological_sort();
        cout << endl;
    }
}