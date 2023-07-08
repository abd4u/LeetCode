//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod=(int)(1e9+7);
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].emplace_back(it[1],it[2]);
            adj[it[1]].emplace_back(it[0],it[2]);
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> tim(n,LONG_MAX),ways(n,0);
        pq.emplace(0,0);
        tim[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long node=pq.top().second;
            long long tm=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long cur_time=it.second;
                if(cur_time+tm<tim[adjNode]){
                    tim[adjNode]=cur_time+tm;
                    ways[adjNode]=ways[node]%mod;
                    pq.emplace(cur_time+tm,adjNode);
                }else if(cur_time+tm==tim[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends