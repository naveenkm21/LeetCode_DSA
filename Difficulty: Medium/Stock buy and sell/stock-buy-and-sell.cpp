class Solution {
public:
    int stockBuySell(vector<int> &arr) {
        int maxProfit = 0;
        
        // Loop through the array starting from the second day
        for (int i = 1; i < arr.size(); i++) {
            // If the price today is higher than yesterday, add the profit
            if (arr[i] > arr[i - 1]) {
                maxProfit += arr[i] - arr[i - 1];
            }
        }
        
        return maxProfit;
    }
};