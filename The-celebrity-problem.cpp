//The celebrity problem
//GFG

/*A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)*/




//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        //step 1 push everyperson to st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        // step 2 compare top 2 persons and run discard method
        while(st.size()!=1){
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            
            //if a knows b;
            if(M[a][b]){
                //a is not celeb b might be 
                st.push(b);
            }
            else{
                //b is not celeb a might be
                st.push(a);
            }
        }
        // step 3 chech that might be celeb is really celeb
        int mightbeceleb=st.top(); st.pop();
        //celeb should not know anyone row==0 all
        for(int i=0;i<n;i++){
            if(M[mightbeceleb][i]!=0){
                return -1;
            }
        }
        //everyone should be celeb col==1 all
        
        for(int i=0;i<n;i++){
            if(M[i][mightbeceleb]==0 && i!=mightbeceleb){
                return -1;
            }
        }
        
        //mightbeceleb is celeb
        return mightbeceleb;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
