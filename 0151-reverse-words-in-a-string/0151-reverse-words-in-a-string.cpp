class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading, trailing and extra spaces
        int n = s.size();
        int i = 0, j = 0;
        
        // Remove leading spaces
        while (i < n && s[i] == ' ') i++;

        string result;
        while (i < n) {
            // Append word
            if (!result.empty()) result += " ";
            while (i < n && s[i] != ' ') result += s[i++];

            // Skip multiple spaces
            while (i < n && s[i] == ' ') i++;
        }

        // Step 2: Reverse entire string
        reverse(result.begin(), result.end());

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= result.size(); ++end) {
            if (end == result.size() || result[end] == ' ') {
                reverse(result.begin() + start, result.begin() + end);
                start = end + 1;
            }
        }

        return result;
    }
};
