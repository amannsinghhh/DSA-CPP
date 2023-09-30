//1047. Remove All Adjacent Duplicates In String
//LC 1047

/*You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

*/



class Solution {
public:
    string removeDuplicates(string s) {
        // int i=0;
        // int j=1;
        // while(j<s.length()){
        //     if(s[i]==s[j]){
        //         s.erase(i,2);
        //         i=max(0,i-1);
        //         j=max(1,j-1);
        //     }
        //     else{
        //         i++;
        //         j++;
        //     }
        // }
        // return s;


        //*********** stack solution ****************

        stack<char> st;
        for(auto ch:s){
            if(!st.empty() && st.top()==ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }   
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
