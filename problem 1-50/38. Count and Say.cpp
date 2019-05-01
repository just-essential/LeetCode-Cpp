/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
class Solution {
public:
    string countAndSay(int n) {
        string result("1"), temp;
        int i, j, count, len;
        char current;
        for (i = 1; i < n; ++i) {
            j = 0;
            len = result.length();
            while (j < len) {
                current = result[j];
                count = 1;
                j++;
                while (current == result[j]) {
                    count++;
                    j++;
                }
                temp += to_string(count) + current;
            }
            result = move(temp);
        }
        return result;
    }

    void test() {
        assert(countAndSay(1) == "1");
        assert(countAndSay(4) == "1211");
    }
};