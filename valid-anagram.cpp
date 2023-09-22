//242. Valid Anagram
//LC 242

/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        //******* brute force **************
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t){
        //     return true;
        // }
        // return false;

        //********* frequency table ***********
        int freqtable[256]={0};
        for(int i=0;i<s.size();i++){
            freqtable[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            freqtable[t[i]]--;
        }
        for(int i=0;i<256;i++){
             if(freqtable[i]!=0){
                 return false;
             }
        }
        return true;
        
    }
};
