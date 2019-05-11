/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i, j, k, c;
        i = a.length() - 1;
        j = b.length() - 1;
        if (j > i) {
            k = j;
        } else {
            k = i;
        }
        string result((unsigned) k + 1, '0');
        c = 0;
        while (k >= 0) {
            result[k] += c;
            if (i >= 0 && a[i--] != '0') {
                result[k]++;
            }
            if (j >= 0 && b[j--] != '0') {
                result[k]++;
            }
            if (result[k] > '1') {
                result[k] -= 2;
                c = 1;
            } else {
                c = 0;
            }
            k--;
        }
        if (c) {
            result.insert(result.begin(), '1');
        }
        return result;
    }

    void test() {
        assert(addBinary("11", "1") == "100");
        assert(addBinary("1010", "1011") == "10101");
    }
};