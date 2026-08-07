class Solution {
public:

    map<int, int> kFactorCounts[10];

    Solution() {
        kFactorCounts[0] = {};
        kFactorCounts[1] = {};
        kFactorCounts[2] = {{2, 1}};
        kFactorCounts[3] = {{3, 1}};
        kFactorCounts[4] = {{2, 2}};
        kFactorCounts[5] = {{5, 1}};
        kFactorCounts[6] = {{2, 1}, {3, 1}};
        kFactorCounts[7] = {{7, 1}};
        kFactorCounts[8] = {{2, 3}};
        kFactorCounts[9] = {{3, 2}};
    }

    pair<map<int, int>, bool> getPrimeCount(long long t) {

        map<int, int> count = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        for (int prime : {2, 3, 5, 7}) {

            while (t % prime == 0) {
                t /= prime;
                count[prime]++;
            }
        }

        return {count, t == 1};
    }

    map<int, int> getPrimeCountFromString(string num) {

        map<int, int> count = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        for (char ch : num) {

            int d = ch - '0';

            for (auto &[prime, freq] : kFactorCounts[d]) {
                count[prime] += freq;
            }
        }

        return count;
    }

    map<int, int> getFactorCount(map<int, int> count) {

        map<int, int> res;

        int count8 = count[2] / 3;
        int remaining2 = count[2] % 3;

        int count9 = count[3] / 2;
        int count3 = count[3] % 2;

        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;

        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }

        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count6 = 1;
            count3 = 0;
            count4 = 0;
        }

        res[2] = count2;
        res[3] = count3;
        res[4] = count4;
        res[5] = count[5];
        res[6] = count6;
        res[7] = count[7];
        res[8] = count8;
        res[9] = count9;

        return res;
    }

    string construct(map<int, int> factors) {

        string res;

        for (int digit = 2; digit < 10; digit++) {

            res += string(
                factors[digit],
                char('0' + digit)
            );
        }

        return res;
    }

    bool isSubset(
        map<int, int> a,
        map<int, int> b
    ) {

        for (auto &[key, value] : a) {

            if (b[key] < value)
                return false;
        }

        return true;
    }

    map<int, int> subtract(
        map<int, int> a,
        map<int, int> b
    ) {

        map<int, int> res = a;

        for (auto &[key, value] : b) {

            res[key] =
                max(0, res[key] - value);
        }

        return res;
    }

    int sumValues(map<int, int> count) {

        int sum = 0;

        for (auto &[key, value] : count)
            sum += value;

        return sum;
    }

    string smallestNumber(string num, long long t) {

        // --------------------------------
        // Step 1: Factorize t
        // --------------------------------

        auto [primeCount, isDivisible] =
            getPrimeCount(t);

        if (!isDivisible)
            return "-1";


        // --------------------------------
        // Step 2: Minimum digit representation
        // --------------------------------

        map<int, int> factorCount =
            getFactorCount(primeCount);

        if (sumValues(factorCount) > num.size()) {
            return construct(factorCount);
        }


        // --------------------------------
        // Step 3: Count factors in num
        // --------------------------------

        map<int, int> primeCountPrefix =
            getPrimeCountFromString(num);


        // Find first zero
        int firstZeroIndex = num.find('0');

        if (firstZeroIndex == string::npos) {

            firstZeroIndex = num.size();

            // num itself works
            if (isSubset(primeCount,
                         primeCountPrefix)) {

                return num;
            }
        }


        // --------------------------------
        // Step 4:
        // Try changing digits from right to left
        // --------------------------------

        for (int i = (int)num.size() - 1;
             i >= 0;
             i--) {

            int d = num[i] - '0';

            // Remove current digit's contribution
            primeCountPrefix =
                subtract(
                    primeCountPrefix,
                    kFactorCounts[d]
                );

            int spaceAfterThisDigit =
                num.size() - 1 - i;

            // Can't have zero in prefix
            if (i > firstZeroIndex)
                continue;


            // Try a larger digit
            for (int biggerDigit = d + 1;
                 biggerDigit < 10;
                 biggerDigit++) {

                auto remainingPrime =
                    subtract(
                        primeCount,
                        primeCountPrefix
                    );

                remainingPrime =
                    subtract(
                        remainingPrime,
                        kFactorCounts[biggerDigit]
                    );

                auto factorsAfterReplacement =
                    getFactorCount(
                        remainingPrime
                    );

                int requiredDigits =
                    sumValues(
                        factorsAfterReplacement
                    );


                // Can fit in remaining space?
                if (requiredDigits <=
                    spaceAfterThisDigit) {

                    int fillOnes =
                        spaceAfterThisDigit
                        - requiredDigits;

                    string answer =
                        num.substr(0, i);

                    answer +=
                        char('0' + biggerDigit);

                    answer +=
                        string(fillOnes, '1');

                    answer +=
                        construct(
                            factorsAfterReplacement
                        );

                    return answer;
                }
            }
        }


        // --------------------------------
        // Step 5:
        // Need a number with one more digit
        // --------------------------------

        auto factorsAfterExtension =
            getFactorCount(primeCount);

        int requiredDigits =
            sumValues(factorsAfterExtension);

        int fillOnes =
            num.size() + 1 - requiredDigits;

        return string(fillOnes, '1') +
               construct(factorsAfterExtension);
    }
};