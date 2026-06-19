class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int,int> freq;

        int maxFreq = 0;

        for(int x:nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }

        int ans = 0;

        for(auto &p : freq) {

            if(p.second == maxFreq){
                ans+=p.second;
            }
        }
        return ans;
    }
};