
class Solution {
public:

    long long calculate(long long k, int m, long long n) {
        long long sum = 1;

        for (int i = 1; i < m; i++) {
            if (sum > (n - 1) / k)
                return n + 1;

            sum = sum * k + 1;

            if (sum > n)
                return n + 1;
        }

        return sum;
    }

    string smallestGoodBase(string n) {

        long long num = stoll(n);

        // Try maximum number of digits first
        for (int m = 60; m >= 2; m--) {

            long long low = 2;
            long long high = num - 1;

            while (low <= high) {

                long long mid = low + (high - low) / 2;

                long long val = calculate(mid, m, num);

                if (val == num)
                    return to_string(mid);

                if (val < num)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        // Every number has a representation of 11 in base n-1
        return to_string(num - 1);
    }
};
