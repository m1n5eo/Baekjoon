#include <iostream>
#include <vector>
using namespace std;

int main() {
    int idx = 0;
    char arr[26];
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        arr[idx++] = ch;
    }
    for(char element : arr) {
        cout << element << " ";
    }
}