class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> candies(n, 1);
        
        // Left to right pass
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        
        // Right to left pass while calculating the total sum
        int ans = candies[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
            ans += candies[i];
        }
        
        return ans;
    }
};
