class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size() + 1;
        long expected = (long)n * (n+1) /2;
        long actual = 0;
        for (int x: arr){
            actual +=x;
        }
        return (int)(expected - actual);
    }
};