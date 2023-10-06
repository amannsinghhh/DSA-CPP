//343. Integer Break
//LC 343

/*Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.*/



class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quot = n / 3;
        int rem = n % 3;
        if (rem == 0) {
            return pow(3, quot);
        } 
        else if (rem == 1) {
            return pow(3, quot - 1) * 4;
        } 
        else {
            return pow(3, quot) * 2;
        }
    }
};
