//
// Created by Moses Ndeda on 12.09.2025.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // set the left and right boundaries
        int left = 0, right = (int)nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if (left > 0 && nums[left - 1] == target)
        {
            return left - 1;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 9, 9, 12}; // Upper bound is 6 as printed by the program i.e. the highest index of 9
    int target = 9;

    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2; // 2 is not present it should return -1

    Solution sol;

    std::cout << "Input vector nums is " << std::endl;
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }
    std::cout << "Index of solution when input is as printed above for nums and target is " << target << " results to " << sol.search(nums, target) << std::endl;

    std::cout << "--------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    vector<int> nums3 = {3};
    int target3 = 3;
    std::cout << "Input vector nums3 is " << std::endl;
    for (int i = 0; i < nums3.size(); i++)
    {
        std::cout << nums3[i] << std::endl;
    }
    std::cout << "Index of solution when input is as printed above for nums3 and target3 is " << target3 << " results to " << sol.search(nums3, target3) << std::endl;
}
