#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i] - 1) > 0) {
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == true) {
                int j = 0, count = 0;
                while (map.count(nums[i] + j) > 0) {
                    j++;
                    count++;
                }
                if (count > maxlen) {
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = solution.longestConsecutive(nums);
    cout << "Length of the longest consecutive sequence is: " << result << endl;

    return 0;
}
