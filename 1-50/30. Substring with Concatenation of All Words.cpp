/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/
class Solution {
public:
    vector<int> findSubstring(string s, const vector<string> &words) {
        if (words.empty() || s.empty() || s.length() < words.size() * words[0].length()) return {};
        auto s_len = s.length(), w_size = words.size(), w_len = words[0].length(), limit = s_len - w_len;
        unordered_map<string, int> count_words;
        vector<int> result;
        for (int i = 0; i < w_size; ++i) {
            count_words[words[i]]++;
        }
        for (int i = 0; i < w_len; ++i) {
            auto left = i, count = 0;
            unordered_map<string, int> flags;
            for (int j = i; j <= limit; j += w_len) {
                auto str = s.substr(j, w_len);
                if (count_words[str]) {
                    count++;
                    if (++flags[str] > count_words[str]) {
                        for (;;) {
                            auto temp = s.substr(left, w_len);
                            flags[temp]--;
                            count--;
                            left += w_len;
                            if (str == temp) break;
                        }
                    }
                    if (count == w_size) {
                        result.push_back(left);
                        flags[s.substr(left, w_len)]--;
                        count--;
                        left += w_len;
                    }
                } else {
                    flags.clear();
                    count = 0;
                    left = j + w_len;
                }
            }
        }
        return result;
    }

    void test() {
        assert(findSubstring("barfoothefoobarman", {"foo", "bar"}) == vector<int>({0, 9}));
        assert(findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}) == vector<int>({}));
    }
};