class Solution {
public:
    bool iscrct(string s) {
        int n = s.length();
        if (s.empty())
            return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
    bool isValid(string str) {
        return (str == "electronics" || str == "grocery" || str == "pharmacy" ||
                str == "restaurant");
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, vector<string>> grouped;
        for (int i = 0; i < n; ++i) {
            if (iscrct(code[i]) && isValid(businessLine[i]) &&
                isActive[i]) {
                grouped[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> result;
        vector<string> order = {"electronics", "grocery", "pharmacy",
                                "restaurant"};
        for (const string& category : order) {
            if (grouped.count(category)) {
                auto& v = grouped[category];
                sort(v.begin(), v.end());
                result.insert(result.end(), v.begin(), v.end());
            }
        }

        return result;
    }
};