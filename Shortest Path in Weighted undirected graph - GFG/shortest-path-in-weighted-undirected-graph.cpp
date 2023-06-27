//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].emplace_back(it[1],it[2]);
            adj[it[1]].emplace_back(it[0],it[2]);
        }
        vector<int> dist(n+1,INT_MAX),parent(n+1),path;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[1]=0;
        pq.emplace(0,1);
        for(int i=1;i<=n;i++) parent[i]=i;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeW=it.second;
                if(dis+edgeW<dist[adjNode]){
                    dist[adjNode]=dis+edgeW;
                    pq.emplace(dis+edgeW,adjNode);
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        int node=n;
        while(node!=parent[node]){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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