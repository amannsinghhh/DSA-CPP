//check if word is valid after substitutions
//Lc 1003

/*Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

 

*/



class Solution {
public:
    bool isValid(string s) {

        //********* slow solution rec ***********

        // if(s.size()==0){
        //     return true;
        // }
        // int find=s.find("abc");
        // if(find!=string::npos){
        //     //found
        //     string tleft=s.substr(0,find);
        //     string tright=s.substr(find+3,s.size());
        //     return isValid(tleft+tright);
        // }
        // return false;

        //************* using stacks *************

        if(s[0]!='a'){
            return false;
        }
        stack<char>st;
        for(char ch:s){
            if(ch=='a'){
                st.push(ch);
            }
            else if(ch=='b'){
                if(!st.empty() && st.top()=='a'){
                    st.push('b');
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() &&st.top()=='b'){
                    st.pop();
                    if(!st.empty()){
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
        return st.empty();
    }
};
