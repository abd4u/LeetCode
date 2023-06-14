//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int newColor,int old_color){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=old_color){
            return;
        }
        image[r][c]=newColor;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            dfs(image,r+row[i],c+col[i],newColor,old_color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int old_color=image[sr][sc];
        if(old_color!=newColor){
            dfs(image,sr,sc,newColor,old_color);
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends