#include <vector>
#include <algorithm> 

class Solution {
public:

    int findLucky(vector<int>& arr) {
        int count[510];
        fill_n(count, 510, 0);


        for (int num : arr) {
            ++count[num];
        }


        int ans = -1;

        for (int i = 1; i < 510; ++i) {
            if (count[i] == i) {
                ans = i; 
            }
        }
        return ans;
    }
};