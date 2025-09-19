//
// Created by Moses Ndeda on 12.09.2025.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
        int mySqrt(int x){
            // for special cases when x is 0 or 1, return x
            if (x==0 || x==1){
                return x;
            }

            //Initialize the search range for the square root.
            int left = 0;
            int right = x;
            int mid = -1; // Mid is invalid to start with.

            //Perform binary search to find the square root of x
            while(left <= right){ //In binary search we always use < or >. The only reason we are using <= i.e. or equal to is because the end/right will become the integer value of the square root once the loop completes
                //Calculate the middle point using "start + (end -start)/2" to avoid integer overflow
                mid = left + (right - left)/2;

                //Convert mid to long long to handle large values without overflow
                //Research the difference between static_cast and just normal cast e.g. (int)
                //long long square = static_cast<long long>(mid * mid); //This solution will work on local machine but give integer overflow in leetcode when x = 2147395599
                //So we will use the below which does not overflow:
                long long square = static_cast<long long>(mid) * mid;


                //If the square of the middle value is greater than x, move the right to the left(mid-1)
                if (square > x){
                    right = mid -1;
                }else if (square == x){
                    return mid; //Hurrah! we have found the square root
                }else{
                    //If the square of the middle value is less than x, move the left to the right of mid i.e. mid+1
                    left = mid+1;
                }
        }

       /*
        * The loop ends when start/left becomes greater than end/right and end/right is the integer value of the square root.
        * However, since we might be using integer devision in the calculations, we round down the value of end/right to the
        * nearest integer in order to get the correct squareroot.
        */

        return static_cast<int> (right);
    }
};

int main() {
    //To get the squareroot
    int target1 = 4;
    int target2 = 8;

    Solution sol;
    std::cout << "Floor of squareroot of "<<target1<<" is " << sol.mySqrt(target1) << std::endl;
    std::cout << "Floor of squareroot of "<<target2<<" is " << sol.mySqrt(target2) << std::endl;
}
