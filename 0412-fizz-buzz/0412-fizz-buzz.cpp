#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;
        result.reserve(n); // Pre-allocate memory to avoid reallocations
        
        int fizzCounter = 1;
        int buzzCounter = 1;
        
        for (int i = 1; i <= n; ++i) {
            if (fizzCounter == 3 && buzzCounter == 5) {
                result.push_back("FizzBuzz");
                fizzCounter = 1;
                buzzCounter = 1;
            } else if (fizzCounter == 3) {
                result.push_back("Fizz");
                fizzCounter = 1;
                buzzCounter++;
            } else if (buzzCounter == 5) {
                result.push_back("Buzz");
                fizzCounter++;
                buzzCounter = 1;
            } else {
                result.push_back(std::to_string(i));
                fizzCounter++;
                buzzCounter++;
            }
        }
        
        return result;
    }
};