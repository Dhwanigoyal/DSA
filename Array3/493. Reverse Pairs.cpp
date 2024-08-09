#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int c = 0;

    int revPairs(vector<int> &a, vector<int> &b) {
        int count = 0;
        int i = 0; // pointer for array a
        int j = 0; // pointer for array b
        while (i < a.size() && j < b.size()) {
            long long int bruh = b[j];
            if (a[i] > 2 * bruh) {
                count += a.size() - i;
                j++;
            } else {
                i++;
            }
        }
        return count;
    }

    void merge(vector<int> &a, vector<int> &b, vector<int> &res) {
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        while (i < a.size()) res[k++] = a[i++];
        while (j < b.size()) res[k++] = b[j++];
    }

    void mergeSort(vector<int> &v) {
        int n = v.size();
        if (n == 1) return;

        int n1 = n / 2, n2 = n - n / 2;
        vector<int> a(n1), b(n2);

        // Copying elements to sub-arrays
        for (int i = 0; i < n1; i++) a[i] = v[i];
        for (int i = 0; i < n2; i++) b[i] = v[i + n1];

        // Recursive merge sort on sub-arrays
        mergeSort(a);
        mergeSort(b);

        // Count reverse pairs
        c += revPairs(a, b);

        // Merge the sorted sub-arrays
        merge(a, b, v);

        // Clear temporary arrays
        a.clear();
        b.clear();
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return c;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 3, 1};

    int result = solution.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}
