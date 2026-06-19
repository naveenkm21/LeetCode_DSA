class Solution {
public:
    int countElements(vector<int>& nums) {
       int mini = *min_element(nums.begin(), nums.end());
       int maxi = *max_element(nums.begin(), nums.end());

       int count = 0;

       for(int num:nums){
            if (num >mini && num <maxi){
                count++;
            }
        }
        return count;        
    } 
};