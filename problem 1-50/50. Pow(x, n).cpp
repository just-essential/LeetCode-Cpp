/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class Solution {
public:
    double myPow(double x, int n) {
        function<double(double, int)> myPowPositive;
        myPowPositive = [&myPowPositive](double x, int n) -> double {
            if (n == 0) {
                return 1;
            }
            if (n == 2) {
                return x * x;
            }
            if (n % 2 == 0) {
                return myPowPositive(myPowPositive(x, n / 2), 2);
            } else {
                return x * myPowPositive(myPowPositive(x, n / 2), 2);
            }
        };
        return n < 0 ? 1 / myPowPositive(x, -n) : myPowPositive(x, n);
    }

    void test() {
        assert(abs(myPow(2, 10) - 1024) < 1e-10);
        assert(abs(myPow(2.1, 3) - 9.261) < 1e-10);
        assert(abs(myPow(2, -2) - 0.25) < 1e-10);
    }
};