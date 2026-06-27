class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 0) return;
        
        // Handle cases where d is greater than the array size
        d %= n;
        
        reverse(arr.begin(), arr.begin() + d);
        
        reverse(arr.begin() + d, arr.end());
        
        reverse(arr.begin(), arr.end());
    }
};