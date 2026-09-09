class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int num : stones){
            pq.push(num);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            int n1 = abs(x - y);
            pq.push(n1);
        }

        return pq.empty() ? 0 : pq.top();
           
    }
};
