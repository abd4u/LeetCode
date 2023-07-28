//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,int parent,vector<int>adj[],vector<int>& vis,vector<int>& low,vector<int>& tin,vector<int>& mark,int& cur_t){
        vis[node]=1;
        tin[node]=low[node]=cur_t;
        cur_t++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,low,tin,mark,cur_t);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1) mark[node]=1;
                child++;
            }
            else low[node]=min(low[node],tin[it]);
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V),low(V),tin(V),mark(V);
        for(int i=0;i<V;i++){
            int cur_t=0;
            if(!vis[i]){
                dfs(i,-1,adj,vis,low,tin,mark,cur_t);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1) ans.emplace_back(i);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends