class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int mx = arr[0];
        for(int x:arr){
            if(x>mx) mx= x;
        }
        return mx;
    }
};
