class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;              // store numbers we have seen
        for (int x : nums) {
            if (seen.count(x)) {             // if x already seen, it must be the repeated one
                return x;
            }
            seen.insert(x);                  // otherwise mark x as seen
        }
        return -1; // won't be reached because problem guarantees an answer
    }
};
