#include <iostream>

using namespace std;

class Solution {
public:
    double calculatePowRecursive(double x, long n) {
        // Terminating conditions
        if (n == 1)
            return x;
        if (n == 0)
            return 1;

        if (n % 4 == 0)
            return calculatePowRecursive(x * x, n / 4) * calculatePowRecursive(x * x, n / 4);
        if (n % 2 == 0)
            return calculatePowRecursive(x * x, n / 2);
        else
            return x * calculatePowRecursive(x, n - 1);
    }

    double myPow(double x, int n) {
        long N = n;
        if (n < 0) {
            N = -N;
            return 1.0 / calculatePowRecursive(x, N);
        }
        return calculatePowRecursive(x, N);
    }
};

int main() {
    Solution solution;
    double x = 2.0;
    int n = 10;

    double result = solution.myPow(x, n);
    cout << "Result of " << x << " raised to the power " << n << " is " << result << endl;

    return 0;
}
