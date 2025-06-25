class Solution {
public:
    long long countPairs(const vector<int>& A, const vector<int>& B, long long x) {
        long long count = 0;
        int m = B.size();

        for (int a : A) {
            if (a > 0) {
                // b <= x / a
                int l = 0, r = m - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if ((long long)a * B[mid] <= x)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                count += l;
            } else if (a < 0) {
                // b >= ceil(x / a)
                int l = 0, r = m - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if ((long long)a * B[mid] <= x)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
                count += m - l;
            } else {
                if (x >= 0) count += m;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long lo = -1e10, hi = 1e10;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countPairs(nums1, nums2, mid) < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
