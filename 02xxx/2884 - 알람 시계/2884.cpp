#include <iostream>
using namespace std;

int main() {
    int h, m, sum = 0; // 24*60 = 1440
    cin >> h >> m;
    sum = h*60 + m;
    if(sum < 45) sum = 1440-(45-sum);
    else sum = sum-45;

    cout << sum/60 << " " << sum%60;
}