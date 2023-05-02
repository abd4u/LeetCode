//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    vector<int> buildlps(string S){
		vector<int> lps(S.length(),0);
		int i=1,j=0;
		while(i<S.length()){
			if(S[i]==S[j]){
				lps[i++]=++j;
			}else{
				if(j==0) lps[i++]=0;
				else j=lps[j-1];
			}
		}
		return lps;
	}
    int findLastOccurence(string A,string B){
        //Code Here
        int ans=-1;
		vector<int> lps=buildlps(B);
		int i=0,j=0;
		for(int i=0,j=0;i<A.length();){
			if(A[i]==B[j]){
				i++;
				j++;
			}
			if(j==B.length()){
				ans=i-j+1;
				j=lps[j-1];
			}else if(i<A.length() && A[i]!=B[j]){
				if(j==0) i++;
				else j=lps[j-1];
			}
		}
		return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends