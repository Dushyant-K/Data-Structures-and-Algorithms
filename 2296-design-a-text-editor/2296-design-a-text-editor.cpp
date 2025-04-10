class TextEditor {
private:
    stack<char> st1; // Left of cursor
    stack<char> st2; // Right of cursor

    string getLast10() {
        string result;
        stack<char> temp = st1;
        int count = 0;
        while (!temp.empty() && count < 10) {
            result += temp.top();
            temp.pop();
            count++;
        }
        reverse(result.begin(), result.end());
        return result;
    }

public:
    TextEditor() {}

    void addText(string text) {
        for (char c : text) {
            st1.push(c);
        }
    }

    int deleteText(int k) {
        int count = 0;
        while (!st1.empty() && k--) {
            st1.pop();
            count++;
        }
        return count;
    }

    string cursorLeft(int k) {
        while (!st1.empty() && k--) {
            st2.push(st1.top());
            st1.pop();
        }
        return getLast10();
    }

    string cursorRight(int k) {
        while (!st2.empty() && k--) {
            st1.push(st2.top());
            st2.pop();
        }
        return getLast10();
    }
};
