#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // return index if target is found in nums, else return -1
    int searchInRotatedArray(vector<int> &nums, int target) 
    // Solution::searchInRotatedArray({6,7,0,1,2,4,5}, 4) ||
    // Solution::searchInRotatedArray({4,5,6,7,0,1,2}, 0) ||
    // Solution::searchInRotatedArray({4,5,6,7,0,1,2}, 3) ||

    {
        int left = 0; //left=0 || left=0 || left=0
        int right = nums.size() - 1; //right=6 || right=6 || right=6

        while (left <= right) 
        // while0<=6, left=0, right=6; while4<=6, left=4, right=6 ||
        // while0<=6, left=0, right=6; while4<=6, left=4, right=6; while 4<=4, left=4, right=4 ||
        // while0<=6, left=0, right=6; while4<=6, left=4, right=6; while 6<=6, left=6, right=6
        {
            int mid = left + (right - left) / 2;
            // mid=3; mid=5; ||
            // mid=3; mid=5; mid=4 ||
            // mid=3; mid=5; mid=6

            if (nums[mid] == target)
            // if1==4?; if4==4? || 
            // if7==0?; if1==0?; if 0==0? ||
            // if7==3?; if1==3?; if2==3?

            {
                return mid;
                // -; 4 XFunc(); ||
                // -; -; 0 XFunc(); ||
                // -; -; -;
            }

            // Check if left upto this mid point is sorted. If we are in the sorted region.
            if (nums[left] <= nums[mid])
            //if 6<=1?; -; ||
            //if 4<=7?; if 0<=1 ||
            //if 4<=7; if 0<=1; 2<=2?

            {

                if (nums[left] <= target && target <= nums[mid]) 
                //-; -; ||
                //if 4<=0&&0<=7?; if 0<=0 &&0<=1
                //if 4<=3&&3<=7?; if 0<=1 && 3<=1?; if 2<=3&&3<=2

                {
                    // left half is sorted and target lies here. Classic binary search applies
                    right = mid - 1; 
                    // -; -; ||
                    // -; right=4 ||
                    // -;-; -;
                }
                else
                {
                    // target is greater than nums[mid] or target < nums[left] despite this left half being sorted
                    left = mid + 1; 
                    //-;-; ||
                    //left=4; -; ||
                    //left=4; left=6; left=7

                }
            }
            // If left up to mid isn't sorted, then we assume right side is sorted.
            else //6>1;
            {
                if (nums[mid] < target && target <= nums[right]) // if 1<4&&4<5; 
                {
                    left = mid + 1; 
                    //left=4 -; ||
                    // -; -; ||
                    // -;-; -;
                }
                else
                {
                    right = mid - 1; 
                    // -; -; ||
                    // -; -; ||
                    // -; -; -;
                }
            }
        }

        return -1; 
        // -; -; ||
        // -; -; ||
        // -; -; -1 XFunc();
        
    }
};

int main()
{
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // int target = 0;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    // vector<int> nums = {6,7,0,1,2,4,5};
    // int target = 4;

    Solution sol;
    std::cout <<"Target is "<< target << " Input is " << std::endl;
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }
    std::cout << "Index of solution is " << sol.searchInRotatedArray(nums, target) << std::endl;
}
