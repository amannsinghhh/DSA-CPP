// 4 september 2023
// Maximize The Cut Segments
//GFG

/*Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Note: if no segment can be cut then return 0.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
        int ans1=(n-x,x,y,z)+1;
        int ans2=(n-y,x,y,z)+1;
        int ans3=(n-z,x,y,z)+1;
        int ans=max(ans1,max(ans2,ans3));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
