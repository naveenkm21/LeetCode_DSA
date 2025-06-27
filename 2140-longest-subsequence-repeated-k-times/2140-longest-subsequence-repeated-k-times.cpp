class Solution {
public:
    bool isSub(const string& s, const string& t, int k) {
        int pos = 0, matched = 0;
        int n = s.size(), m = t.size();
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        vector<char> cand;
        for(int i=25;i>=0;i--){
            if(freq[i]>=k){
                cand.push_back('a'+i);
            }
        }
        queue<string> q;
        for (char ch : cand) {
            q.push(string(1, ch));
        }

        string ans="";
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr.size()>ans.size()){
                ans=curr;
            }
            for(char ch:cand){
                string next=curr+ch;
                if(isSub(s,next,k)){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};