#include <iostream>
using namespace std;

void print(int num) {
    if(num == 0) return;
    cout << "recursive" << "\n";
    print(--num);
}

int main() {
    int n = 3;
    cin >> n;
    print(n);
}