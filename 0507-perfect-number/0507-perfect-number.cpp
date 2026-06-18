class Solution {
public:
    bool checkPerfectNumber(int n) {

        if(n<=1){
            return false;
        }

        int sum = 1;

        for(int i = 2; i < n; i++){
            if(n % i == 0) {
                sum += i; 
            }
        }
        return sum == n;
    }
};