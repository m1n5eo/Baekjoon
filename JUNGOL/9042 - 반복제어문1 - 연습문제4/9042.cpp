#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int num, cnt = 0, sum = 0;
    while(1) {
        cin >> num;
        if(num == 0) break;
        sum += num;
        cnt += 1;
    }
    cout << "입력된 자료의 개수 = " << cnt << "\n";
    cout << "입력된 자료의 합계 = " << sum << "\n";
    cout << "입력된 자료의 평균 = " << round((double)sum/(double)cnt*100)/100;
}