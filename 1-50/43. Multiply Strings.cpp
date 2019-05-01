/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        int len1 = num1.length(), len2 = num2.length();
        string result(len1 + len2, 0);
        int i, j, current;
        for (i = 0; i < len1; i++) {
            num1[i] -= '0';
        }
        for (i = 0; i < len2; i++) {
            num2[i] -= '0';
        }
        for (i = len1 - 1; i >= 0; i--) {
            for (j = len2 - 1; j >= 0; j--) {
                current = i + j + 1;
                result[current] += (num1[i]) * (num2[j]);
                result[current - 1] += result[current] / 10;
                result[current] %= 10;
            }
        }
        for (auto &n:result) {
            n += '0';
        }
        return result[0] == '0' ? result.substr(1) : result;
    }

    void test() {
        assert(multiply("2", "3") == "6");
        assert(multiply("123", "456") == "56088");
    }
};