//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
public:
    vector<int> parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mpMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpMailNode.find(mail)!=mpMailNode.end()){
                    ds.unionBySize(i,mpMailNode[mail]);
                }else mpMailNode[mail]=i;
            }
        }
        vector<vector<string>> mergedMail(n),ans;
        for(auto it:mpMailNode){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergedMail[node].emplace_back(mail);
        }
        for(int i=0;i<n;i++){
            if(!mergedMail[i].empty()){
                vector<string> temp;
                sort(mergedMail[i].begin(),mergedMail[i].end());
                temp.emplace_back(accounts[i][0]);
                for(auto it:mergedMail[i]) temp.emplace_back(it);
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends