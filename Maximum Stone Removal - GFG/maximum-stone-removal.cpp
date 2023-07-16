//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int x) {
        // Code here
        int m=0,n=0;
        for(auto it:stones){
            m=max(m,it[0]);
            n=max(n,it[1]);
        }
        DisjointSet ds(m+n+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            ds.unionBySize(it[0],m+1+it[1]);
            stoneNodes[it[0]]=1;
            stoneNodes[m+1+it[1]]=1;
        }
        int ans=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first) ans++;
        }
        return x-ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends