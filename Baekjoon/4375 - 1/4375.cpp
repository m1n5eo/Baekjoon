#include <iostream>
using namespace std;

int n;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(cin >> n) {
        int num = 1, result = 1;

        while(num%n != 0) {
            num = (num*10 + 1) % n;
            result += 1;
        }

        cout << result << "\n";
    }
}