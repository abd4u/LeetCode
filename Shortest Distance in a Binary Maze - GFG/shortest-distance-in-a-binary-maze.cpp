//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        dis[source.first][source.second]=0;
        q.push({0,source});
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int cur_dis=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && r<m && c>=0 && c<n && grid[r][c] && cur_dis+1<dis[r][c]){
                    dis[r][c]=cur_dis+1;
                    q.push({dis[r][c],{r,c}});
                }
            }
        }
        return (dis[destination.first][destination.second]==INT_MAX)?-1:dis[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends