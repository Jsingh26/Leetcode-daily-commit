class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int maxval = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            maxval = max(maxval, right - left + 1);
        }

        return maxval;
    }
};