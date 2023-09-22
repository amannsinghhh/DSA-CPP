//917. Reverse Only Letters

//Lc 917

/*Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.*/



class Solution {
public:
    string reverseOnlyLetters(string s) {
        int b=0;
        int e=s.size()-1;
        while(b<e){
            if(isalpha(s[b]) && isalpha(s[e])){
                swap(s[b],s[e]);
                b++;
                e--;
            }
            else if(!isalpha(s[b])){
                b++;
            }
            else{
                e--;
            }

        }
        return s;
    }   
};
