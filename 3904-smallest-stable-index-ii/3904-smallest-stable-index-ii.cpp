class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefmax(n);
        vector<int> prefmin(n);
        prefmax[0] = nums[0];
        prefmin[n-1] = nums[n-1];
        if(nums.size()==1) return 0;
        int res = 0;

        for(int i = 1; i < n;i++){
            prefmax[i] = max(nums[i],prefmax[i-1]);
        }
        for(int i = n - 2; i >= 0;i--){
            prefmin[i] = min(nums[i],prefmin[i+1]);

        }

        for(int i = 0;i<n;i++){
            if(prefmax[i]-prefmin[i] <= k){
                return i;
            }
        }
        return res != 0 ? res : -1 ;
    }
};