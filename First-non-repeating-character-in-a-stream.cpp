//First non-repeating character in a stream
//GFG


/*Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int freq[26]={0};
		    queue<char>q;
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];
		        
		        //index 0-A.....25-Z increment freq
		        freq[ch-'a']++;
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(freq[q.front()-'a']>1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		                
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
