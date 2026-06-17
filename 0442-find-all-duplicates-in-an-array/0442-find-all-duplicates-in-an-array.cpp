class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        unordered_map<int,int> freq;
        vector<int> ans;

        for(int num:nums){
            freq[num]++;
        }
        for(auto it:freq){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};