//14. Longest Common Prefix
//LC 14

/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char curr=0;
            for(auto str : strs){
                if(i>=str.size()){
                    curr=0;
                    break;

                }
                if(curr==0){
                    curr=str[i];
                }
                else if(str[i]!=curr){
                    curr=0;
                    break;
                }
            }
            if(curr==0){
                break;

            }
            ans.push_back(curr);
            i++;
        }
        return ans;
    }
};
