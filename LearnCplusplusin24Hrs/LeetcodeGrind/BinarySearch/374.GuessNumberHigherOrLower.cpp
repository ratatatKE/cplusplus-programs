//
// Created by Moses Ndeda on 12.09.2025.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 0;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int result = guessforTenPick6(mid);
            if (result == 0)
            { // we have matched
                return mid;
            }
            else if (result == 1) // guess is lower than the number so eliminate the current lower half where the guess is and switch to the upper half
            {
                left = mid + 1;
            }
            else // guess is higher than the number so eliminate the current higher half where the guess is in and switch to the lower half
            {
                right = mid - 1;
            }
        }

        return -1;
    }

private:
    int guessforTenPick6(int n)
    {
        if (n == 6)
        {
            return 0;
        }
        else if (n > 6)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    // To get the squareroot
    int range1 = 10;

    Solution sol;
    std::cout << "For a range of 0 to " << range1 << " with a pick of 6, the program returned " << sol.guessNumber(range1) << std::endl;
}
