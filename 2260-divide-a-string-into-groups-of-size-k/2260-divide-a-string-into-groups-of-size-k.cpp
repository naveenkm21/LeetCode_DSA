class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int N = s.size();
        vector<string> res;
        
        for (int i = 0; i < N; i += k) {
            string grp = s.substr(i, k);
            
            while (grp.size() < k) {
                grp += fill;
            }
            
            res.push_back(grp);
        }

        return res;
    }
};
