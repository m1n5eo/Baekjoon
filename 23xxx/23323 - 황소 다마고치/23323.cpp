#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli testcase;

int main() {
    FASTIO

    cin >> testcase;

    while(testcase--) {
        lli health, feed;

        cin >> health >> feed;

        lli result = feed;

        while(health) {
            health /= 2;
            result += 1;
        }

        cout << result << "\n";
    }

    return 0;
}