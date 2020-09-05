#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// Given an integer array nums, find the sum of the elements between indices i
// and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i
// to val.

// Example:

// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

// Constraints:

// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is
// distributed evenly. 0 <= i <= j <= nums.length - 1

class NumArray {
   public:
    vector<int> MyNums;
    NumArray(vector<int>& nums) { MyNums = nums; }

    void update(int i, int val) { MyNums[i] = val; }

    int sumRange(int i, int j) {
        return accumulate(MyNums.begin() + i, MyNums.begin() + j + 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
    vector<int> B = {1, 2, 3, 4, 5};
    NumArray A(B);
    cout << A.sumRange(0, 1) << endl;
    system("Pause");
}