class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // If the next character is also ')',
                // consume both closing parentheses.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert a missing '('.
                    ans++;
                }
            }
        }

        return ans + 2 * open;
    }
};