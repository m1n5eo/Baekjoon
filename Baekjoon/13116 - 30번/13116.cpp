#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int t;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int a, b;

        cin >> a >> b;

        while(a != b) {
            if(a > b) a /= 2;
            else if(a < b) b /= 2;
        }

        cout << b*10 << "\n";
    }
}