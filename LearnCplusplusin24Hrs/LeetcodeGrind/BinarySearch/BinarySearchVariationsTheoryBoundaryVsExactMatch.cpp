/*

This file serves to explain variations of binary searches i.e. when do you use < and when do you use <=

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findInsertionPoint(int arr[], int n, int target)
    {
        int left = 0;
        int right = n; //Note that right =n and NOT n-1, we might insert at the VERY end

        // WHY right = n? Because for array {1, 3, 5, 7, 9} which has a size of 5, 5 is out of bounds when indexing but it is valid for insertion as it is at the VERY end
        
        while (left < right){
            int mid = left + (right - left)/2;

        }
    }
};

int main()
{
    // let us implement the testcase for findInsertionPoint
    Solution sol;

    int arr1[] = {1, 3, 5, 7, 9};
    cout << "During the test for findInsertionPoint() with array [1,3,5,7,9], we expected position 3 and we got -> " << sol.findInsertionPoint(arr1, 5, 6) << endl;
}