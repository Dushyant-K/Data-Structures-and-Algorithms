class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    // Stack to hold opening brackets
    std::stack<char> stack;

    for (char c : s) {
        // If the character is a closing bracket
        if (bracketMap.count(c)) {
            // Get the top element of the stack if it exists, else assign a dummy value
            char topElement = stack.empty() ? '#' : stack.top();
            stack.pop();
            // Check if the popped element matches the corresponding opening bracket
            if (topElement != bracketMap[c]) {
                return false;
            }
        } else {
            // It's an opening bracket, push onto the stack
            stack.push(c);
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return stack.empty();
    }
};