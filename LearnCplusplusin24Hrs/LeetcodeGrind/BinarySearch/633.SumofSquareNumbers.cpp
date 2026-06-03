#include <iostream>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int a = 0; a * a <= c; a++)
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
    int c = 5;
    std::cout << "input is " << c << std::endl;
    sol.judgeSquareSum(c);
}




// input = 5 i.e. c=5
class SolutionGDBInHead
{
public:
    bool judgeSquareSum(int c) 						//c=5; 
    {
        for (int a = 0; a * a <= c; a++)			//a=0, 0*0<=5, a++; || a=1, 1*1<=5, 1++; || -
        {
            int b = c - (int)(a * a);				// b=5; || b=4 || 1
            if (binarySearch(0, b, b))				// binarySearch(0,5,5)=false || binarySearch(0,4,4)=true 
            {
                std::cout << "when a is " << a <<std::endl;
                return true;						// - || true, breaks this function() and returns to main()
            }
        }
        // after we are done through all subsets and there is nothing, return false.
        return false;
    }


    bool binarySearch(long left, long right, int target) // binarySearch(0,5,5); || binarySearch(0,4,4) 
    {
        while (left <= right)							// while(0<=5); while(3<=5); while(3<=3); while(3<=2)=false,break; || while(0<=4); 
        {
            long mid = left + ((right - left) / 2);     // mid=2; mid=4; mid=3; || mid =2; 


            if (target == mid * mid)					// 5==2*2?; 5==4*4?; 5 == 3*3? || 4 ==2*2?yes; 
            {
                std::cout << "the answer is " << mid << std::endl; 	// - ; -; -; || 2; 
                return true;										//  -; -; -; || true, breaks this FUNCTION because while{} and returns to outer for{};
            }
            else if (target > mid * mid)				// 5>2*2?; 5>4*4?; 5>3*3? || -
            {
                left = mid + 1;							// left=3; - ; -; || -
            }
            else										//	- ; 5<4*4 ; 5<3*3; || -
            {
                right = mid - 1;						// - ; right=3; right=2; || right = 2
            }
        }


        return false;									// -; -; -; false;
    }
};


int mainGDBInHead()
{
    Solution sol;
    int c = 5;
    std::cout << "input is " << c << std::endl;
    sol.judgeSquareSum(c);
}

