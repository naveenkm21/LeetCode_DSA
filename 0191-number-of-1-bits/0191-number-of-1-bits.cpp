class Solution {
 public:
  int hammingWeight(uint32_t n) {
    return popcount(n);
  }
};