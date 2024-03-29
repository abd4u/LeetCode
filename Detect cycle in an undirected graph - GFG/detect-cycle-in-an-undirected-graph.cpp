//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /*bool detect(int src,vector<int> adj[],vector<int>& vis){
        queue<pair<int,int>> q;
        vis[src]=1;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjnode:adj[node]){
                if(!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push({adjnode,node});
                }else if(parent!=adjnode ) return true;
            }
        }
        return false;
    }*/
    bool detect(int node,int parent,vector<int> arr[],vector<int>& vis){
        vis[node]=1;
        for(auto adjnode:arr[node]){
            if(!vis[adjnode]){
                if(detect(adjnode,node,arr,vis)) return true;
            }else if(parent!=adjnode) return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends