class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        istringstream iss(s);
        string word;
        int i = 0;
        
        while (iss >> word) {
            if (i >= pattern.size()) return false;
            char c = pattern[i];
            if (p2w.count(c) && p2w[c] != word) return false;
            if (w2p.count(word) && w2p[word] != c) return false;
            p2w[c] = word;
            w2p[word] = c;
            i++;
        }
        return i == pattern.size();
    }
};
