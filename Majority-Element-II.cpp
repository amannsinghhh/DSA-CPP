//229. Majority Element II
//LC 229

/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> result;
        for (int num : nums) {
            count[num]++;
        }
        int n = nums.size();
        for (auto& entry : count) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};
