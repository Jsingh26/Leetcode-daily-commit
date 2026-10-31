class Solution {
public:

    bool canFinish(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {

            hours += (piles[i] + (long long)k - 1) / k;

            if(hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canFinish(piles, h, mid)) {

                ans = mid;
                high = mid - 1;

            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};