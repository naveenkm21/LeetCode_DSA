class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        bool seen[256] = {false};
        string res;
        for (char c:s){
            if (!seen[(unsigned char)c]){
                seen[(unsigned char)c] = true;
                res+=c;
            }
        }
        return res;
    }
};