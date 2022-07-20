#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        
        map<char, vector<pair<int, string>> > letters;
        for (auto &word : words) {
            letters[word[0]].push_back({0, word});
        }
        for (int i = 0; i < s.size(); ++i) {
            vector<pair<int, string>> new_letter;
            for (auto &word : letters[s[i]]) {
                if (word.second.size() == word.first + 1) {
                    res++;
                } else {
                    if (s[i] == word.second[word.first + 1]) {
                        new_letter.push_back({word.first + 1, word.second});
                    } else {
                        letters[word.second[word.first + 1]].push_back({word.first + 1, word.second});
                    }
                }
            }
            letters[s[i]] = new_letter;
        }
        return res;
    }
};

int main()
{
    string s = "dsahjpjauf";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    Solution sol;
    std::cout << sol.numMatchingSubseq(s, words) << std::endl;

    return 0;
}