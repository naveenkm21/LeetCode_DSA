class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;  

        for (const string& token : tokens) {
            if (token.size() == 1 && string("+-*/").find(token) != string::npos) {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                switch (token[0]) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            } else {
                st.push_back(stoi(token));
            }
        }

        return st.back();
    }
};
