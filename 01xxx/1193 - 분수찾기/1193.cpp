#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n, x = 1, y = 1, sw = 1, k = 1;

    cin >> n;

    while(true) {
        if(k == n) break;
        else if(x == 1 || y == 1) {
            sw = 1-sw;
            k += 1;

            if(sw == 0) y += 1;
            else if(sw == 1) x += 1;
        }
        
        if(k == n) break;
        else if(sw == 0) {
            x += 1;
            y -= 1;
        }
        else if(sw == 1) {
            x -= 1;
            y += 1;
        }

        k += 1;
    }

    cout << x << "/" << y;
}