//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    grid[i][j]=0;
                }
                
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int cur_size=q.size();
            for(int i=0;i<cur_size;i++){
                pair<int,int> node=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int r=node.first+delrow[i];
                    int c=node.second+delcol[i];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
                        q.push({r,c});
                        grid[r][c]=0;
                    }
                }
            }
            cnt++;
        }
        for(auto x:grid){
            for(auto y:x){
                if(y>0) return -1;
            }
        }
        return cnt-1>=0?cnt-1:0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends