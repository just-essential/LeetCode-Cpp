/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem,
assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN) return 0;
        int result = 0;
        bool sign = false;
        if (x < 0) {
            x = -x;
            sign = true;
        }
        while (x > 9) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if (result > INT_MAX / 10) return 0;
        result = result * 10 + x % 10;
        return sign ? -result : result;
    }

    void test() {
        assert(reverse(123) == 321);
        assert(reverse(-123) == -321);
        assert(reverse(120) == 21);
    }
};