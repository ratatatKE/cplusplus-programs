//
// Created by Moses Ndeda on 12.09.2025.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {

        int left = 0;
        int right = x;
        int mid = left + (right - left) / 2;
        if (x == 0 || x == 1)
        {
            return x;
        }
        // if not x returned, then call the recursion
        return recursiveSqrt(left, right, x);
    }

private:
    int recursiveSqrt(int left, int right, int target)
    {
        // We have to calculate mid and square afresh every time we enter into the recursion
        int mid = left + (right - left) / 2;
        long long square = (mid) * mid; // Long long to handle large numbers

        if (left > right)
        {
            // Break out of the loop since there will be no solution
            /*
            We repeat step 4 to 8 until the left pointer becomes greater than the right pointer.
            At this point, we have found the floor value of the square root and the right pointer holds
            the value.
            */
            return right;
        }
        else if (square > target)
        {
            right = mid - 1; // the square root lies in the lower half
            return recursiveSqrt(left, right, target);
        }
        else if (square < target)
        {
            left = mid + 1; // the square root lies in the upper half;
            return recursiveSqrt(left, right, target);
        }
        else if (square == target)
        {
            return mid; // Hurrah!, we have found the square root.
        }
        else
        {

            // otherwise i.e. after we have gone through all the conditions, return -1 since there's no solution
            return -1;
        }
    }
};

int main()
{
    // To get the squareroot
    int target1 = 4;
    int target2 = 8;

    Solution sol;
    std::cout << "Floor of squareroot of " << target1 << " is " << sol.mySqrt(target1) << std::endl;
    std::cout << "Floor of squareroot of " << target2 << " is " << sol.mySqrt(target2) << std::endl;
}
