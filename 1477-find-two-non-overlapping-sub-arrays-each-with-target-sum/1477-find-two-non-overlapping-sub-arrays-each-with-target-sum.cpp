class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // best[i] = minimum length of a target-sum subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);
        
        int left = 0;
        long long sum = 0;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            // Shrink window if sum becomes too large
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // If current window has sum = target
            if (sum == target) {
                int len = right - left + 1;
                
                // Need a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }
                
                // This is the best target subarray ending at/before right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                // Carry forward previous best
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};