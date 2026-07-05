class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers for nums1, nums2, and the placement position at the end of nums1
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, copy them
        // (If there are remaining elements in nums1, they are already in place)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};