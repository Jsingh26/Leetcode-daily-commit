class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        char mid = 0;
        bool hasMid = false;
        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;
                hasMid = true;
            }
            half[i] = freq[i] / 2;
        }

        int halfLen = n / 2;
        string firstHalf = "";
        long long kk = k;

        while ((int)firstHalf.length() < halfLen) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;
                half[c]--;

                long long ways = 1;
                long long placed = 0;
                for (int x = 0; x < 26; x++) {
                    for (int j = 1; j <= half[x]; j++) {
                        placed++;
                        ways = ways * placed / j;
                        if (ways > kk) {
                            ways = kk + 1;
                            break;
                        }
                    }
                    if (ways > kk)
                        break;
                }

                if (ways >= kk) {
                    firstHalf += (char)('a' + c);
                    found = true;
                    break;
                } else {
                    kk -= ways;
                    half[c]++;
                }
            }
            if (!found)
                return "";
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        string ans = firstHalf;
        if (hasMid)
            ans += mid;
        ans += secondHalf;
        return ans;
    }
};