#include <iostream>
using namespace std;

int main() {
    int num, cnt = 0, sum = 0;
    while(1) {
        cin >> num;
        if(num == 0) break;
        if(num%2) {
            sum += num;
            cnt += 1;
        }
    }
    cout << "홀수의 합 = " << sum << "\n";
    cout << "홀수의 평균 = " << sum/cnt;
}
