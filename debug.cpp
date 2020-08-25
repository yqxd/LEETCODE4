#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<vector<int> > a = {{1, 2}, {2, 3, 4}, {1, 3}};
    for (auto i : a) {
        for (auto j : i) {
            cout << j << endl;
        }
    }
}
