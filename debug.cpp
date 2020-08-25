#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<int> a = {1, 2, 3, 4};
    a.erase(a.begin() + 1 : a.begin() + 2);
    for (auto i : a)
        cout << i << endl;
}
