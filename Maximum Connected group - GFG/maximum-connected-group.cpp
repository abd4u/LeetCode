//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int r=drow[k]+i;
                        int c=dcol[k]+j;
                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]){
                            if(ds.findUPar(i*n+j)!=ds.findUPar(r*n+c)){
                                ds.unionBySize(i*n+j,r*n+c);
                            }
                        }
                    }
                }
            }
        }
        int largest_island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int r=drow[k]+i;
                        int c=dcol[k]+j;
                        if(r>=0 && c>=0 && r<n && c<n && grid[r][c]){
                            st.insert(ds.findUPar(r*n+c));
                        }
                    }
                    for(auto it:st) cnt+=ds.size[it];
                }
                if(cnt>0)largest_island=max(largest_island,cnt+1);
            }
        }
        if(largest_island==0) return (grid[0][0]==1)?n*n:1;
        return largest_island;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends