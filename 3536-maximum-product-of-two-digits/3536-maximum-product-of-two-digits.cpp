class Solution {
public:
    int maxProduct(int n) {
    vector<int> arr;
    while(n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }

    sort(arr.begin(), arr.end());
    int i = arr.size();
    return arr[i-1]*arr[i-2];
    }
};