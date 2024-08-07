#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int next_greater(vector<int> nums, int i) {
        for(int j = nums.size() - 1; j > i - 1; j--) {
            if(nums[j] > nums[i - 1])  return j;
        }
        return i;
    }

    void nextPermutation(vector<int>& nums) {
        int k;
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                k = next_greater(nums, i);
                swap(nums[i - 1], nums[k]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    cout << "Original vector: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
