class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> res(26, -1);

        for(int i = 0; i < s.size(); i++) {
            int num = s[i] - 'a';

            if(res[num] == -1) {
                res[num] = i;           // store first occurrence
            }
            else {
                int dist = i - res[num] - 1;

                if(dist != distance[num])
                    return false;
            }
        }

        return true;
    }
};