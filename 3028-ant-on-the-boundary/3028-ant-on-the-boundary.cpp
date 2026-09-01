class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int total = 0;
        int ans = 0;
        for(int num : nums){
            total += num;
            if(total == 0){
                ans ++;
            }
        }
        return ans;
    }
};