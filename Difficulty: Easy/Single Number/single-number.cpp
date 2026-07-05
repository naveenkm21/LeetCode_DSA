class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int ans = 0;
        for(int a:arr){
            ans^=a;
        }
        return ans;
    }
};