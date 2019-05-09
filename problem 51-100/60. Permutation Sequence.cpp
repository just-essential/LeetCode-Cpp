/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 2)
            return "1";
        int fac[n];
        n--, k--;
        int i, j;
        string result;
        vector<int> rest;
        for (i = 0; i <= n; ++i) {
            rest.push_back(i);
        }
        fac[n] = 1;
        fac[n - 1] = 1;
        for (i = n - 2; i >= 0; --i) {
            fac[i] = fac[i + 1] * (n - i);
        }
        for (i = 0; i < n; ++i) {
            j = k / fac[i];
            k %= fac[i];
            result.push_back(rest[j] + '1');
            rest.erase(rest.begin() + j);
        }
        result.push_back(rest[0] + '1');
        return result;
    }

    void test() {
        assert(getPermutation(3, 3) == "213");
        assert(getPermutation(4, 9) == "2314");
    }
};