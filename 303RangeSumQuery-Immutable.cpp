// Given an integer array nums, find the sum of the elements between indices i
// and j (i ≤ j), inclusive.

// Example:

// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3

// Constraints:

// You may assume that the array does not change.
// There are many calls to sumRange function.
// 0 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5
// 0 <= i <= j < nums.length

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NumArray {
   public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a = nums;
        for (int i = 1; i < a.size(); i++) {
            a[i] = a[i - 1] + a[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return a[j];
        } else {
            return a[j] - a[i - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
    vector<int> a = {1, 2, 3, 4};
    NumArray A = NumArray(a);
    cout << A.sumRange(1, 3) << endl;
}