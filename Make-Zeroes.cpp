// 1 September 2023
//Make Zeros
//GFG

//Given a matrix of  size n x m. Your task is to make Zeroes, that means in whole matrix when you find a zero, convert its upper, lower, left 
//and right value to zero and make that element the sum of the upper, lower, left and right value. Do the following tasks according to the initial matrix.

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    void MakeZeros(vector<vector<int> >& arr) {
        
        // Code here
        vector<vector<int> >temp=arr;
        int row=arr.size();
        int col=arr[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(temp[i][j]==0){
                    if(i+1<row){
                        arr[i][j]+=temp[i+1][j];
                        arr[i+1][j]=0;
                    }
                    if(i-1>=0){
                        arr[i][j]+=temp[i-1][j];
                        arr[i-1][j]=0;
                    }
                    if(j+1<col){
                        arr[i][j]+=temp[i][j+1];
                        arr[i][j+1]=0;
                    }
                    if(j-1>=0){
                        arr[i][j]+=temp[i][j-1];
                        arr[i][j-1]=0;
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
