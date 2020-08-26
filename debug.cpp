#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> a = {"1", "2"};
    a.pop_back();
    cout << a[0] << endl;
    a.pop_back();

    a.push_back("1");
    a.push_back("1");
    a.push_back("1");
    for (auto i : a) {
        cout << i << endl;
    }
    cout << 'i' << endl;
}
