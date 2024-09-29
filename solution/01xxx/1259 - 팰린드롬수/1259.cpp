#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    while(true) {
        int num;

        cin >> num;

        if(num == 0) {
            break;
        }

        int save = num, reverse = 0;

        while(num != 0) {
            reverse = reverse*10 + num%10;
            num /= 10;
        }

        if(save == reverse) cout << "yes" << "\n";
        else if(save != reverse) cout << "no" << "\n";
    }
}