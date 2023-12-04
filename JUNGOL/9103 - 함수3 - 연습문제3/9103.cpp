#include <iostream>
using namespace std;

void print(int num, int res) {
    if(num == 0) {
        cout << res;
        return;
    }
    print(num-1, res*num);
}

int main() {
    int n;
    cin >> n;
    print(n, 1);
}