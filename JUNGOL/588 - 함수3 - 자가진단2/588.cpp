#include <iostream>
using namespace std;

void print(int num) {
    if(num == 0) return;
    cout << num << " ";
    print(--num);
}

int main() {
    int n;
    cin >> n;
    print(n);
}