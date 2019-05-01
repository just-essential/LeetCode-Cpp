/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int quotient = 0, sign = (dividend >= 0) ^(divisor > 0), i = sizeof(int) * 8;
        unsigned a = dividend < 0 ? static_cast<unsigned int>(~dividend) + 1 : dividend, b =
                divisor < 0 ? static_cast<unsigned int>(~divisor) + 1 : divisor;
        while (i--) {
            quotient = quotient << 1;
            if ((a >> i) >= b) {
                quotient++;
                a -= (b << i);
            }
        }
        if (sign) return -quotient;
        else return quotient;
    }

    void test() {
        assert(divide(10, 3) == 3);
        assert(divide(7, -3) == -2);
    }
};