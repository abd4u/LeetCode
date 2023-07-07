//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].emplace_back(it[1],it[2]);
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> price(n,INT_MAX);
        price[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int node=q.front().second.first;
            int cur_price=q.front().second.second;
            int stop=q.front().first;
            q.pop();
            if(stop<=K){
                for(auto it:adj[node]){
                    if(cur_price+it.second<price[it.first]){
                        price[it.first]=cur_price+it.second;
                        q.push({stop+1,{it.first,price[it.first]}});
                    }
                }
            }
        }
        return (price[dst]==INT_MAX)?-1:price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends