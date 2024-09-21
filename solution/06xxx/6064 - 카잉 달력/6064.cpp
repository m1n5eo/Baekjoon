#include <iostream>
using namespace std;

int lcm(int a, int b) {
    int aa = a, bb = b;
    if(a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return aa*bb/a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, x, y, t;
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n >> m >> x >> y;
        int lcmnm = lcm(n, m), k = -1;
        for(int i = x; i <= lcmnm; i+=n) {
            if(i%m == y%m) {
                k = i;
                break;
            }
        }
        cout << k << "\n";
    }
}