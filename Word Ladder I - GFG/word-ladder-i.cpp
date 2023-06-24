//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st;
        for(auto it:wordList){
            if(it!=startWord) st.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({startWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int cur_len=q.front().second;
            q.pop();
            for(int i=0;i<s.length();i++){
                string temp=s;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(st.find(temp)!=st.end()){
                        if(temp==targetWord) return cur_len+1;
                        q.push({temp,cur_len+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends