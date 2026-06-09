#include <string>
#include <stack>
#include <algorithm>

class BrowserHistory {
private:
    std::stack<std::string> backHistory;
    std::stack<std::string> forwardHistory;
    std::string current;

public:
    BrowserHistory(std::string homepage) {
        current = homepage;
    }
    
    void visit(std::string url) {
        backHistory.push(current);
        current = url;
        forwardHistory = std::stack<std::string>(); 
    }
    
    std::string back(int steps) {
        while (steps > 0 && !backHistory.empty()) {
            forwardHistory.push(current);
            current = backHistory.top();
            backHistory.pop();
            steps--;
        }
        return current;
    }
    
    std::string forward(int steps) {
        while (steps > 0 && !forwardHistory.empty()) {
            backHistory.push(current);
            current = forwardHistory.top();
            forwardHistory.pop();
            steps--;
        }
        return current;
    }
};