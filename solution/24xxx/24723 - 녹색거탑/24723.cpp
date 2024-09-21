#include <iostream>
using namespace std;

int main() {
    int n, temp = 1;
    cin >> n;
    for(int i = 0; i < n; i++) temp *= 2;
    cout << temp;
}