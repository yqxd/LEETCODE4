// Remove the minimum number of invalid parentheses in order to make the input
// string valid. Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and
// ).

// Example 1:

// Input: "()())()"
// Output: ["()()()", "(())()"]
// Example 2:

// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
// Example 3:

// Input: ")("
// Output: [""]

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {}
    int check(vector<char> s) {
        vector<char> result = {};
        for (auto i : s) {
            if (i == '(') {
                result.push_back('(');
            } else if (i == ')') {
                if (result.size() == 0)
                    return false;
                if (result[result.size() - 1] == '(') {
                    result.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (result.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    string s = {'1', '(', ')', '(', '(', ')', ')'};
    Solution A;
    if (A.check(s)) {
        cout << 1 << endl;
    }
}