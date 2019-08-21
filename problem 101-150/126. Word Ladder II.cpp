/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> result;
        queue<vector<string>> q;
        unordered_set<string> words;
        unordered_set<string> visited;
        for (auto &word: wordList) {
            words.insert(word);
        }
        // start from level 1
        int level = 1;
        int minLevel = INT_MAX;
        q.push({beginWord});
        // when there is an incomplete path
        while (!q.empty()) {
            // get the first path
            vector<string> path = q.front();
            q.pop();
            // when current level is larger
            // delete words you've visited
            // to avoid getting a longer path
            if (path.size() > level) {
                level = path.size();
                // only need all shortest transformation sequence(s)
                if (level > minLevel) {
                    break;
                }
                for (auto &word : visited) {
                    words.erase(word);
                }
                visited.clear();
            }
            // transform the last word
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                char temp = last[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    last[i] = c;
                    // transformation is in the list
                    if (words.find(last) != words.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(last);
                        visited.insert(last);
                        // get a solution
                        // push it into result
                        // and set the minimum level
                        if (last == endWord) {
                            minLevel = level;
                            result.push_back(newPath);
                        } else {
                            q.push(newPath);
                        }
                    }
                }
                last[i] = temp;
            }
        }
        return result;
    }

    void test() {
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        assert(findLadders("hit", "cog", wordList) == vector<vector<string>>({{"hit", "hot", "dot", "dog", "cog"},
                                                                              {"hit", "hot", "lot", "log", "cog"}}));
        wordList = {"hot", "dot", "dog", "lot", "log"};
        assert(findLadders("hit", "cog", wordList) == vector<vector<string>>({}));
    }
};