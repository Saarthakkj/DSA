class Solution {
public:
    void reverseSubstring(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseParentheses(string s) {
        stack<int> s1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                s1.push(i);
            } else if (s[i] == ')') {
                int start = s1.top();
                s1.pop();
                reverseSubstring(s, start + 1, i - 1);
            }
        }


        string result = "";
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

        return result;
    }
};
