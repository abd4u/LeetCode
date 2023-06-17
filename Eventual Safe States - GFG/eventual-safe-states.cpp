//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int s,vector<int> adj[],vector<int>& vis){
        vis[s]=2;
        for(auto it:adj[s]){
            if(vis[it]==0){
                if(dfs(it,adj,vis)) return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[s]-=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V),ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(!dfs(i,adj,vis)) ans.emplace_back(i);
            }else if(vis[i]==1) ans.emplace_back(i);
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends