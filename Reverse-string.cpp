// 5September 2023
//REverse string
//LC 344

/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 */

//*********iterative sol****************

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int e=s.size()-1;
        while(st<=e){
            swap(s[st],s[e]);
            st++;
            e--;
        }
    }
};


//*********  recursive sol****************

class Solution {
public:

    void reverse(vector<char>& s, int st, int e){
        if(st>=e){
            return;
        }

        swap(s[st],s[e]);
        reverse(s,st+1,e-1);
    }
    void reverseString(vector<char>& s) {
        int st=0;
        int e=s.size()-1;
        // while(st<=e){
        //     swap(s[st],s[e]);
        //     st++;
        //     e--;
        // }
        reverse(s,st,e);

    }
};
