// 20. Valid Parentheses
//LC 20

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char topch=st.top();
                    if(ch==')' && topch=='('){
                        st.pop();
                    }
                    else if(ch=='}' && topch=='{'){
                        st.pop();
                    }
                    else if(ch==']' && topch=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else {
            return false;
        }
    }
};
