class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minPos = 0;
        int maxPos =  0;
        int n = nums.size();

        for(int i = 0;i<nums.size();i++){
            if(nums[i]>nums[maxPos]){
                maxPos = i;
            }
            if (nums[i]<nums[minPos]){
                minPos = i;
            }
        }
        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

                // Option 1: both removed from front
        int fromFront = right + 1;

        // Option 2: both removed from back
        int fromBack = n - left;

        // Option 3: left one from front, right one from back
        int bothSides = (left + 1) + (n - right);

        return min({fromFront, fromBack, bothSides});
        
    }
};