#include <iostream>
using namespace std;

int sum, cnt;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true) {
        int temp;
        cin >> temp;

        if(!(0 <= temp && temp <= 100)) break;

        sum += temp;
        cnt += 1;
    }

    cout << "sum : " << sum << "\n";
    cout.precision(1);
    cout << fixed;
    cout << "avg : " << (double)sum/(double)cnt;
}