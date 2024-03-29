//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /*bool check(int s,int V,vector<int>adj[],vector<int>& color){
        queue<int> q;
	    q.push(s);
	    color[s]=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node]){
	            if(color[it]==-1){
	                q.push(it);
	                color[it]=!color[node];
	            }
	            else if(color[it]==color[node]) return false;
	        }
	    }
	    return true;
    }*/
    bool dfs(int s,vector<int>adj[],vector<int>& color,int cur_color){
        color[s]=cur_color;
        for(auto it:adj[s]){
            if(color[it]==-1){
                if(!dfs(it,adj,color,!cur_color)) return false;
            }else if(color[it]==cur_color) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   vector<int> color(V,-1);
	   for(int i=0;i<V;i++){
	       if(color[i]==-1){
	           if(!dfs(i,adj,color,0)) return false;
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends