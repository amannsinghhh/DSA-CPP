//Largest-rectangle-in-histogram
//LC 84

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

*/



class Solution {
public:

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
};
