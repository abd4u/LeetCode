//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0' || vis[r][c]==1) return;
        vis[r][c]=1;
        dfs(grid,vis,r-1,c);
        dfs(grid,vis,r+1,c);
        dfs(grid,vis,r,c-1);
        dfs(grid,vis,r,c+1);
        dfs(grid,vis,r-1,c-1);
        dfs(grid,vis,r+1,c-1);
        dfs(grid,vis,r-1,c+1);
        dfs(grid,vis,r+1,c+1);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends