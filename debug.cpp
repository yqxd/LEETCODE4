#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<int> a = {1, 2, 3, 4};
    for (auto i : a)
        cout << i << endl;
}
