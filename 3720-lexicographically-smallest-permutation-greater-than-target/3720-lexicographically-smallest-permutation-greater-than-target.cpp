class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> count(26, 0);

        // Count characters in s
        for (char ch : s) {
            count[ch - 'a']++;
        }

        int n = target.size();
        int matched = 0;

        // Match target as far as possible
        while (matched < n) {

            int x = target[matched] - 'a';

            if (count[x] == 0)
                break;

            count[x]--;
            matched++;
        }

        // Try to increase the first unmatched position
        if (matched < n) {

            int x = target[matched] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (count[c] > 0) {

                    count[c]--;

                    string suffix = "";

                    for (int j = 0; j < 26; j++) {
                        suffix += string(count[j], char(j + 'a'));
                    }

                    return target.substr(0, matched)
                         + char(c + 'a')
                         + suffix;
                }
            }
        }

        // Backtrack through the matched prefix
        for (int i = matched - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Restore target[i]
            count[x]++;

            // Find the smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (count[c] > 0) {

                    count[c]--;

                    string suffix = "";

                    for (int j = 0; j < 26; j++) {
                        suffix += string(count[j], char(j + 'a'));
                    }

                    return target.substr(0, i)
                         + char(c + 'a')
                         + suffix;
                }
            }
        }

        return "";
    }
};