class Solution {
  public:
    vector<int> find(vector<int>& a, int target) {
        // code here
        int lo = 0, hi = a.size() - 1, res2 = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] == target) { res2 = mid; lo = mid + 1; }
            else if (a[mid] < target) lo = mid + 1;
            else hi = mid - 1;
            
        }
        lo = 0, hi = a.size() - 1;
        int res1= -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] == target) { res1 = mid; hi = mid - 1; }
            else if (a[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return {res1,res2};
    }
};