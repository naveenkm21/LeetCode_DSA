class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Try every offset within a word
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seen;
            int left = i, count = 0;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
