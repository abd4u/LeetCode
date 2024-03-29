//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int s,vector<int> adj[],vector<int>& vis){
        vis[s]=2;
         //pathvis[s]=1;
        for(auto it:adj[s]){
            if(vis[it]==0){
                if(dfs(it,adj,vis)) return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[s]-=1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends