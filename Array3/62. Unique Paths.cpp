#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> aboveRow(n, 1);

        for (int row = 1; row < m; row++) {
            vector<int> currentRow(n, 1);
            for (int col = 1; col < n; col++) {
                currentRow[col] = currentRow[col - 1] + aboveRow[col];
            }
            aboveRow = currentRow;
        }

        return aboveRow[n - 1];
    }
};

int main() {
    Solution solution;
    int m = 3, n = 7;

    int result = solution.uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
