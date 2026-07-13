class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        priority_queue <int,vector<int>,greater<int>> pq;

        for(int n : nums){
            pq.push(n);
        }

        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
        }
        long long ans=1;
        while(!pq.empty()){
            ans = (pq.top()*ans) % MOD;
            pq.pop();
        }
        return ans;
    }
};