/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
//    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
//        queue<string> lastWordQueue;
//        queue<int> levelQueue;
//        unordered_set<string> words(wordList.begin(),wordList.end());
//        unordered_set<string> visited;
//        // start from level 1
//        int level = 1;
//        lastWordQueue.push(beginWord);
//        levelQueue.push(1);
//        // when there is an incomplete path
//        while (!lastWordQueue.empty()) {
//            // get the first path
//            string lastWord = lastWordQueue.front();
//            int currentLevel = levelQueue.front();
//            lastWordQueue.pop();
//            levelQueue.pop();
//            // when current level is larger
//            // delete words you've visited
//            // to avoid getting a longer path
//            if (currentLevel > level) {
//                level = currentLevel;
//                for (auto &word : visited) {
//                    words.erase(word);
//                }
//                visited.clear();
//            }
//            // transform the lastWord word
//            for (int i = 0; i < lastWord.size(); ++i) {
//                char temp = lastWord[i];
//                for (char c = 'a'; c <= 'z'; ++c) {
//                    lastWord[i] = c;
//                    // transformation is in the list
//                    if (words.find(lastWord) != words.end()) {
//                        if (lastWord == endWord) {
//                            return currentLevel + 1;
//                        }
//                        visited.insert(lastWord);
//                        lastWordQueue.push(lastWord);
//                        levelQueue.push(currentLevel + 1);
//                    }
//                }
//                lastWord[i] = temp;
//            }
//        }
//        return 0;
//    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        unordered_set<string> s1{beginWord}, s2{endWord};
        int wordLength = beginWord.size();
        int result = 0;
        while (!s1.empty() && !s2.empty()) {
            ++result;
            if (s1.size() > s2.size()) {
                swap(s1, s2);
            }
            unordered_set<string> transformations;
            for (string word:s1) {
                for (int i = 0; i < wordLength; ++i) {
                    char temp = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (s2.find(word) != s2.end()) {
                            return result + 1;
                        }
                        if (words.find(word) == words.end()) {
                            continue;
                        }
                        words.erase(word);
                        transformations.insert(word);
                    }
                    word[i] = temp;
                }
            }
            swap(s1, transformations);
        }
        return 0;
    }

    void test() {
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        assert(ladderLength("hit", "cog", wordList) == 5);
        wordList = {"hot", "dot", "dog", "lot", "log"};
        assert(ladderLength("hit", "cog", wordList) == 0);
    }
};