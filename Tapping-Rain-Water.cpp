// Tapping Rain Water 
// LC 42

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n),right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],arr[i])+0ll;
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i])+0ll;
        }
        int ans=0ll;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;

    }
};
