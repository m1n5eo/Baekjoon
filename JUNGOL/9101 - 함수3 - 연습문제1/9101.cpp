#include <iostream>
using namespace std;

void print(int num) {
    if(num == 0) return;
    cout << "홍길동" << "\n";
    print(--num);
}

int main() {
    int n = 10;
    print(n);
}