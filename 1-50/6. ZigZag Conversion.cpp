/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = static_cast<int>(s.length()), turn_len = (numRows - 1) << 1;
        string result;
        for (int j = 0; j < len; j += turn_len) {
            result.push_back(s[j]);
        }
        for (int i = 1; i < numRows - 1; ++i) {
            for (int j = i; j < len; j += turn_len) {
                result.push_back(s[j]);
                if (j + turn_len - (i << 1) < len) {
                    result.push_back(s[j + turn_len - (i << 1)]);
                }
            }
        }
        for (int j = numRows - 1; j < len; j += turn_len) {
            result.push_back(s[j]);
        }
        return result;
    }

    void test() {
        assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
        assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    }
};