//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>> vis(m,vector<int>(n));
	    queue<pair<int,int>> q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){ 
	                q.push({i,j});
	                grid[i][j]=-1;
	            }
	        }
	    }
	    int drow[]={-1,0,1,0};
	    int dcol[]={0,1,0,-1};
	    int cnt=1;
	    while(!q.empty()){
	        int cur_size=q.size();
	        for(int i=0;i<cur_size;i++){
	            int r=q.front().first;
    	        int c=q.front().second;
    	        q.pop();
    	        for(int j=0;j<4;j++){
    	            int row=r+drow[j],col=c+dcol[j];
    	            if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==0){
    	                vis[row][col]=cnt;
    	                q.push({row,col});
    	                grid[row][col]=-1;
    	            }
    	        }
	        }
	        cnt++;
	    }
	    return vis;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends