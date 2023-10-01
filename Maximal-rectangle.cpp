//Maximal rectangle
//LC 85

/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/



class Solution {
public:

    //******** this is max area of a rect histogram ************

    vector<int> immediateSmaller(vector<int>&arr){
            //  code here
            stack<int> s;
            s.push(-1);
            vector<int> ans(arr.size());
            for(int i=arr.size()-1;i>=0;i--){
                int curr=arr[i];
                while(s.top()!=-1 &&  arr[s.top()]>=curr){
                    s.pop();
                }
                ans[i]=s.top();
                s.push(i);
            }
            return ans;
    }
    vector<int> prevSmaller(vector<int>&arr){
            //  code here
            stack<int> s;
            s.push(-1);
            vector<int> ans(arr.size());
            for(int i=0;i<arr.size();i++){
                int curr=arr[i];
                while(s.top()!=-1 &&  arr[s.top()]>=curr){
                    s.pop();
                }
                ans[i]=s.top();
                s.push(i);
            }
            return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        //step 1 get prevsmaller element
        vector<int> prev=prevSmaller(heights);
        //step 2 get nextsmaller element
        vector<int> next=immediateSmaller(heights);
        int maxArea=INT_MIN;
        int size=heights.size();
        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            if(next[i]==-1){
                next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int> t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        //********* this is the code ********************
        
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};
