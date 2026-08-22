class Solution {
public:
    bool checkDivisibility(int n) {
        int divide = n;
        int sum = 0;
        int product = 1;
        while(n){
            int new_num = n % 10;
            sum = new_num + sum;
            product = new_num * product;
            n/=10;
        }
        if(divide % (sum + product) == 0){
            return true;
        }
        return false;
    }
};