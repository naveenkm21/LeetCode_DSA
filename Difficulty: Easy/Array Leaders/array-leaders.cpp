class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> res;
        int mx = -1;
        
        for(int i = arr.size() - 1; i>=0; i--){
            if(arr[i] >= mx){
                res.push_back(arr[i]);
                mx = arr[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};