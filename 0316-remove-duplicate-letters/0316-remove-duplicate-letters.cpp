class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        string res = "";
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : s) {
            count[c - 'a']--;
            if (inStack[c - 'a']) {
                continue;
            }

            while (!res.empty() && res.back() > c && count[res.back() - 'a'] > 0) {
                inStack[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return res;
    }
};