// Given a string s and a string t, check if s is subsequence of t.

// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ace" is a
// subsequence of "abcde" while "aec" is not).

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
// want to check one by one to see if T has its subsequence. In this scenario,
// how would you change your code?

// Credits:
// Special thanks to @pbrother for adding this problem and creating all test
// cases.

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int now = 0;
        if (s.size() == 0) {
            return false;
        }
        for (int i = 0; i < t.size(); i++) {
            if (s[now] == t[i]) {
                now++;
                if (now == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution A;
    cout << A.isSubsequence("1345", "12345");
    system("Pause");
}