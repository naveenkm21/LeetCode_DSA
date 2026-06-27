class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int first = -1, second = -1;
        for(int x : arr){
            if(x>first) {
                second = first;
                first = x;
            }
            else if (x>second && x!=first){
                second = x;
            }
        }
        return second;
    }
};