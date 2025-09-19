//
// Created by Moses Ndeda on 12.09.2025.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        // Find the insertion point 'idx'
        int idx = upper_bound(nums.begin(), nums.end(), target)  - nums.begin(); // So upper_bound returns and index, then you subtract nums.begin to get the absolute?

        if (idx > 0 && nums[idx -1]==target){
            return idx -1;
        }else{
        return -1;
        }
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 9, 9, 12}; //Lower bound is 4 as printed by program i.e. the lowest index of 9 in the vecor
    int target = 9;

    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // int target = 2; //2 is not present it should return -1

    Solution sol;
    std::cout << "Input is " << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }
    std::cout << "Index of solution is " << sol.search(nums, target) << std::endl;
}
