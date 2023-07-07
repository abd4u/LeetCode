//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=pow(10,5);
        queue<pair<int,int>> q;
        vector<int> dist(pow(10,5),INT_MAX);
        q.push({0,start});
        dist[start]=0;
        while(!q.empty()){
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            if(node==end) return steps;
            for(int i=0;i<arr.size();i++){
                int prod=(node*arr[i])%mod;
                if(steps+1<dist[prod]){
                    if(prod==end) return steps+1;
                    dist[prod]=steps+1;
                    q.emplace(steps+1,prod);
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends