#include <iostream>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            int b = c - (int)(a * a);
            if (binarySearch(0, b, b))
            {
                std::cout << "when a is " << a <<std::endl;
                return true;
            }
        }
        // after we are done through all subsets and there is nothing, return false.
        return false;
    }

    bool binarySearch(long left, long right, int target)
    {
        // if (left > right)
        //     return false;

        // long mid = left + ((right - left) / 2);

        // if (mid * mid == target)
        // {
        //     std::cout << mid << std::endl;
        //     return true;
        // }

        // if (mid * mid > target)
        // {
        //     return binarySearch(left, mid - 1, target);
        // }

        // return binarySearch(mid + 1, right, target);

        while (left <= right)
        {
            long mid = left + ((right - left) / 2);

            if (target == mid * mid)
            {
                std::cout << "the answer is " << mid << std::endl;
                return true;
            }
            else if (target > mid * mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    int c = 36;
    std::cout << "input is " << c << std::endl;
    sol.judgeSquareSum(c);
}