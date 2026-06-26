class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        int n = word.length();
        
        for (char c : word) {
            if (isupper(c)) {
                count++;
            }
        }

        return count == n || count == 0 || (count == 1 && isupper(word[0]));
    }
};