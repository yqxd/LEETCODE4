// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for
// the first two numbers, each subsequent number in the sequence must be the sum
// of the preceding two.

// Given a string containing only digits '0'-'9', write a function to determine
// if it's an additive number.

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence
// 1, 2, 03 or 1, 02, 3 is invalid.

// Example 1:

// Input: "112358"
// Output: true
// Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
//              1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// Example 2:

// Input: "199100199"
// Output: true
// Explanation: The additive sequence is: 1, 99, 100, 199.
//              1 + 99 = 100, 99 + 100 = 199

// Constraints:

// num consists only of digits '0'-'9'.
// 1 <= num.length <= 35

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     bool check(string x1, string x2, string y) {
//         if (y == "") {
//             return true;
//         } else {
//             long long n1 = atoi(x1.c_str());
//             n1 += atoi(x2.c_str());
//             string n = to_string(n1);
//             if (n.length() > y.length() || n != y.substr(0, n.length())) {
//                 return false;
//             } else {
//                 return check(x2, n, y.substr(n.length()));
//             }
//         }
//     }
//     bool isAdditiveNumber(string num) {
//         long long n = num.length();
//         if (n <= 2) {
//             return false;
//         } else if (num.substr(0, 1) == "0") {
//             long long n1 = 1;
//             if (num.substr(n1, 1) != "0") {
//                 for (long long n2 = 1; n2 < n - n1; n2++) {
//                     if (check(num.substr(0, n1), num.substr(n1, n2),
//                               num.substr(n1 + n2))) {
//                         return true;
//                     }
//                 }
//             } else {
//                 if (check(num.substr(0, n1), num.substr(n1, 1),
//                           num.substr(n1 + 1))) {
//                     return true;
//                 }
//             }
//             return false;
//         }
//         for (long long n1 = 1; n1 <= n / 2; n1++) {
//             if (num.substr(n1, 1) != "0") {
//                 for (long long n2 = 1; n2 < n - n1; n2++) {
//                     if (check(num.substr(0, n1), num.substr(n1, n2),
//                               num.substr(n1 + n2))) {
//                         return true;
//                     }
//                 }
//             } else {
//                 if (check(num.substr(0, n1), num.substr(n1, 1),
//                           num.substr(n1 + 1))) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// int main() {
//     Solution A;
//     if (A.check("11111111111", "0", "11111111111")) {
//         cout << 1;
//     } else {
//         cout << 2;
//     }
// }

class Solution {
   public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;
        int n1Index = 0;
        for (int n2Index = 1; n2Index < num.size(); ++n2Index) {
            if (num[n2Index] == '0') {
                // Begin with 0, n2 is 0
                if (isAdditiveNumber(num, n1Index, n2Index, n2Index + 1))
                    return true;
                continue;
            }
            for (int n3Index = n2Index + 1; n3Index < num.size(); ++n3Index) {
                if (isAdditiveNumber(num, n1Index, n2Index, n3Index))
                    return true;
            }
        }
        return false;
    }

    bool isAdditiveNumber(const string& num,
                          int n1Index,
                          int n2Index,
                          int n3Index) {
        int n1Len = n2Index - n1Index;
        int n2Len = n3Index - n2Index;
        int sumLen = max(n1Len, n2Len);
        // a + b = c, len(c) = max(len(a), len(b)) or max(len(a), len(b)) + 1
        if (num.size() - n3Index < sumLen)
            return false;
        // Begin with 0, n2 is 0
        if (num[n3Index] == '0') {
            if (sumLen > 1)
                return false;
            else if (isSum(num, n1Index, n2Index, n3Index, 1)) {
                if (n3Index + 1 == num.size())
                    return true;
                else
                    return isAdditiveNumber(num, n2Index, n3Index, n3Index + 1);
            } else {
                return false;
            }
        }
        if (isSum(num, n1Index, n2Index, n3Index, sumLen)) {
            if (n3Index + sumLen == num.size())
                return true;
            return isAdditiveNumber(num, n2Index, n3Index, n3Index + sumLen);
        } else if (isSum(num, n1Index, n2Index, n3Index, sumLen + 1)) {
            if (n3Index + sumLen + 1 == num.size())
                return true;
            return isAdditiveNumber(num, n2Index, n3Index,
                                    n3Index + sumLen + 1);
        } else {
            return false;
        }
    }

    bool isSum(const string& num,
               int n1Index,
               int n2Index,
               int n3Index,
               int n3Len) {
        int i = n2Index - 1;
        int j = n3Index - 1;
        int k = n3Index + n3Len - 1;
        int flag = 0;
        while (i >= n1Index && j >= n2Index && k >= n3Index) {
            int sum = num[i] - '0' + num[j] - '0' + flag;
            flag = sum >= 10 ? 1 : 0;
            if ((sum % 10 + '0') != num[k])
                return false;
            i--;
            j--;
            k--;
        }

        while (i >= n1Index) {
            int sum = num[i] - '0' + flag;
            flag = sum >= 10 ? 1 : 0;
            if ((sum % 10 + '0') != num[k])
                return false;
            i--;
            k--;
        }

        while (j >= n2Index) {
            int sum = num[j] - '0' + flag;
            flag = sum >= 10 ? 1 : 0;
            if ((sum % 10 + '0') != num[k])
                return false;
            j--;
            k--;
        }
        if (flag == 1) {
            return (k == n3Index && num[k] == '1');
        } else {
            return true;
        }
    }
};