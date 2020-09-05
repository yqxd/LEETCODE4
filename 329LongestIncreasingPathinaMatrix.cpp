// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or
// down. You may NOT move diagonally or move outside of the boundary (i.e.
// wrap-around is not allowed).

// Example 1:

// Input: nums =
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: nums =
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
// is not allowed.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> d(matrix.size());
        for (auto i : matrix) {
            for (auto j : i) {
                i.push_back(-1);
            }
        }
        vector<int> result = findmin(matrix, d);
        while (result[1] == -1) {
        }
    }
    vector<int> findmin(vector<vector<int>> matrix, vector<vector<int>> d) {
        vector<int> result = {10000, -1, -1};
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (d[i][j] == -1) {
                    if (result[0] > matrix[i][j]) {
                        result[0] = matrix[i][j];
                        result[1] = i;
                        result[2] = j;
                    }
                }
            }
        }
        return result;
    }
    void alter(vector<vector<int>> matrix,
               vector<vector<int>> d,
               int i,
               int j) {
        if ()
    }
};