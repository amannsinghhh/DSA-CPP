// 7 september 2023
//17. Letter Combinations of a Phone Number
// LC 17

/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/



class Solution {
public:

    void solve(vector<string> &ans,int index, string output, string digits, vector<string> &mapping){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        //1 case solve baaki recursion
        int digit=digits[index]-'0';
        string value=mapping[digit];
        for(int i=0;i<value.length();i++){
            char ch=value[i];
            output.push_back(ch);
            solve(ans,index+1,output,digits,mapping);
            //backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        int index=0;
        string output="";
        vector<string> mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(ans,index,output,digits,mapping);
        return ans;
    }
};
