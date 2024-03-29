//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int src,vector<pair<int,int>> adj[],vector<int>& vis,stack<int>& st){
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it.first]){
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].emplace_back(edges[i][1],edges[i][2]);
        }
        vector<int> dist(N,INT_MAX);
        dist[0]=0;
        vector<int> vis(N);
        stack<int> st;
        dfs(0,adj,vis,st);
        while(!st.empty()){
            int cur_dis=dist[st.top()];
            for(auto it:adj[st.top()]){
                dist[it.first]=min(cur_dis+it.second,dist[it.first]);
            }
            st.pop();
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends