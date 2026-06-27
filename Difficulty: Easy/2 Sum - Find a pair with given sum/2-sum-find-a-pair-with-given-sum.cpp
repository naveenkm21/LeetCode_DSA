class Solution {
  public:
    vector<int> twoSum(vector<int> &arr, int target) {
        // code here
        unordered_set<int> seen;
        for(int i = 0; i<arr.size(); i++){
            int need = target - arr[i];
            if(seen.count(need)){
                return{need, arr[i]};
            }
            seen.insert(arr[i]);
        }
        return {};
    }
};