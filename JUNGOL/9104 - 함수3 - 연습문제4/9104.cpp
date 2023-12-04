#include <iostream>
using namespace std;

void print(int num, int res) {
    if(num == 0) {
        cout << res;
        return;
    }
    print(num/10, res+num%10);
}

int main() {
    int n;
    cin >> n;
    print(n, 0);
}