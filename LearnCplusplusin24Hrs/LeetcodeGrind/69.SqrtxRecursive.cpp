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
        //if not x returned, then call the recursion
        return recursiveSqrt(left, right, x);
    }

private:
    int recursiveSqrt(int left, int right, int target)
    {
        // We have to calculate mid and square afresh every time we enter into the recursion
        int mid = left + (right - left) / 2;
        long long square = mid * mid; // Long long to handle large numbers

        if (left > right)
        {
            // Break out of the loop since there will be no solution
            // return right; // The right will be the square root at this point imagine.
            //We could have returned -1 to mean there is no solution but imagine with a squareroot problem there will always be asolution so we just return right.
            return -1;// I think the returning -1 is the right approach and fits with our philosphy in recursion
        }
        else if (square > target)
        {
            right = mid - 1; // the square root lies in the lower half
            recursiveSqrt(left, right, target);
        }
        else if (square < target)
        {
            left = mid + 1; // the square root lies in the upper half;
            recursiveSqrt(left, right, target);
        }

        // otherwise i.e. after we have gone through all the conditions, then return mid since it will be our solution
        // returning mid here also covers for the case where square == target.
        return mid;
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
