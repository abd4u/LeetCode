//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid,vector<pair<int,int>>& res,int i,int j,int r,int c,vector<vector<int>>& vis){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || !grid[r][c] || vis[r][c]) return;
        res.emplace_back(r-i,c-j);
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            dfs(grid,res,i,j,r+drow[k],c+dcol[k],vis);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> res;
                    dfs(grid,res,i,j,i,j,vis);
                    st.insert(res);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends