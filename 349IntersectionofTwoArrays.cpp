#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:

// Each element in the result must be unique.
// The result can be in any order.

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        make_heap(nums1.begin(), nums1.end());
        make_heap(nums2.begin(), nums2.end());
    };

    int main() {
        vector<int> a = {1, 2, 3, 4, 5}, b = {1, 3, 5, 7};
        Solution A;
        for (auto i : A.intersection(a, b)) {
            cout << i << endl;
        }
        system("Pause");
    }