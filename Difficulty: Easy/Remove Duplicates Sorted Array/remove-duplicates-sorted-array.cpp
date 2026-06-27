class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &nums) {
        // code here
        if(nums.empty()){
            return {};
        }
        int j = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[j]){
                nums[++j] = nums[i];
            }
        }
        nums.resize(j+1);
        return nums;
    }
};