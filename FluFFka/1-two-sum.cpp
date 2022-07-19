#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> start = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (nums[left] + nums[right] != target) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        vector<int> res(2);
        for (int i = 0; i < start.size(); ++i) {
            if (nums[left] == start[i]) {
                res[0] = i;
                break;
            }
        }
        for (int i = start.size() - 1; i >= 0; --i) {
            if (nums[right] == start[i]) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> a = s.twoSum(nums, target);
    cout << a[0] << " " << a[1] << endl;

    return 0;
}