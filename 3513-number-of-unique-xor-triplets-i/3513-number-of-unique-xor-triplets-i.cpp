class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return n;

        int k = 0;
        int t = n;
        while (t) {
            k++;
            t >>= 1;
        }

        return 1 << k;
    }
};