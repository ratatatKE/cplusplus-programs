#include <algorithm>
//
// Created by Moses Ndeda on 08.09.2025.
//
using namespace std;
#include <vector>
#include <iostream>

/*
 *       Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 *
 *       You must write an algorithm with O(log n) runtime complexity.

 *

 *       Example 1:

 *       Input: nums = [-1,0,3,5,9,12], target = 9
 *       Output: 4
 *       Explanation: 9 exists in nums and its index is 4
 *       Example 2:

 *       Input: nums = [-1,0,3,5,9,12], target = 2
 *       Output: -1
 *       Explanation: 2 does not exist in nums so return -1
 *
 */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = (int) nums.size() - 1;
        int mid = left + ((right - left) / 2);
        return recursivebinarysearch(nums, left, right, mid, target);
    }

private:
    int recursivebinarysearch(vector<int> &nums, int left, int right, int mid, int target) {
        //We need to get out of the recursion. This is the base case
        if (left > right) {
            //Break out of the recursion to avoid a segfault. If left and right cross then we have a problem
            return -1;
        } else if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
            mid = left + ((right - left) / 2);
            return recursivebinarysearch(nums, left, right, mid, target);
        } else if (nums[mid] > target) {
            right = mid - 1;
            mid = left + ((right - left) / 2);
            return recursivebinarysearch(nums, left, right, mid, target);
        } else {
            //If we have finished the search and never found a target, return -1
            return -1;
        }
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
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
