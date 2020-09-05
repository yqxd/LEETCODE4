#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isPowerOfFour(int num) {
        long now = 1;
        while (now < num) {
            now = now * 4;
        }
        return now == num;
    }
};

int main() {
    Solution A;
    cout << A.isPowerOfFour(125) << endl;
    system("Pause");
}