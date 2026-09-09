class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int,int>>
        > pq;

        for(auto& num : points){
            int a = num[0];
            int b = num[1];

            int dist = a*a + b*b;

            pq.push({dist, {a,b}});


            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){

            ans.push_back({
                pq.top().second.first,
                pq.top().second.second
            });
            pq.pop();

        }
        return ans;
    }
};