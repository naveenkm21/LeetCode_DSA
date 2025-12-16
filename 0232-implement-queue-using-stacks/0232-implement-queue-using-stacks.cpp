class MyQueue {
public:
    stack<int> inStack, outStack;

    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        moveIfNeeded();
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        moveIfNeeded();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    void moveIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};
