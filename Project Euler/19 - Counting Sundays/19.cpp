#include <iostream>
using namespace std;

// 1901.01.01 - TUE
// SUN(0) MON(1) TUE(2) WED(3) THU(4) FRI(5) SAT(6)
// 31 28,29 31 30 31 30 31 31 30 31 30 31

int main() {
    int now = 2, cnt = 0, days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int year = 1901; year <= 2000; year++) {
        if(year%4 == 0 && year%400 != 0) days[2] = 29;
        else days[2] = 28;
        for(int month = 1; month <= 12; month++) {
            now = now + days[month]%7;
            if(now%7 == 0) cnt++;
        }
    }
    if(now%7 == 0) cnt--;
    cout << cnt;
}