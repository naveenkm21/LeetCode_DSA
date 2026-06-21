class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        int missing = t.size();

        int start = -1;
        int minLen = INT_MAX;

        for(char c : t)
            freq[c]++;

        for(int left = 0, right = 0; right < s.size(); right++) {

            if(--freq[s[right]] >= 0)
                missing--;

            while(missing == 0) {

                if(right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                if(++freq[s[left++]] > 0)
                    missing++;
            }
        }

        return start == -1
               ? ""
               : s.substr(start, minLen);
    }
};